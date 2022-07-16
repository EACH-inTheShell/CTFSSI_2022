#include "map.hpp"
#include "net.hpp"

#include <arpa/inet.h>
#include <chrono>
#include <cstring>
#include <iostream>
#include <memory.h>
#include <netdb.h>
#include <string>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <termios.h>
#include <thread>
#include <unistd.h>

constexpr std::string_view CSI = "\x1b[";
constexpr unsigned short WIN_HEIGHT = 10;
constexpr unsigned short WIN_WIDTH = 30;

namespace graphics {
	void clean()
	{
		std::cout << CSI << 'u' << CSI << 'J' << std::flush;
	}

	void start()
	{
		std::cout
		    << "Aperte 'q' para sair a qualquer momento ou '?' para ajuda\n";
		termios term;
		tcgetattr(STDIN_FILENO, &term);
		term.c_lflag &= ~ICANON;
		tcsetattr(STDIN_FILENO, TCSADRAIN, &term);

		std::cout << CSI << '?' << 25 << 'l';
		for (int i = 0; i < WIN_HEIGHT; ++i)
			std::cout << std::endl;
		std::cout << CSI << WIN_HEIGHT << 'A' << CSI << 's' << std::flush;
	}

	void stop()
	{
		std::cout << CSI << '?' << 25 << 'h' << CSI << 'u' << CSI << WIN_HEIGHT
		          << "B" << std::flush;
		termios term;
		tcgetattr(STDIN_FILENO, &term);
		term.c_lflag |= ICANON;
		tcsetattr(STDIN_FILENO, TCSADRAIN, &term);
	}

	void render(Map map, int pos_x, int pos_y)
	{
		clean();
		std::cout << map << CSI << 'u' << CSI << pos_y << 'B' << CSI << pos_x
		          << 'C' << '@' << std::flush;
	}

	void print_message(const std::string& message)
	{
		clean();
		std::cout << "Received a message:\n\n\t" << message << std::endl;
	}
};

void help()
{
	graphics::clean();
	std::cout << std::endl;
	std::cout << "          k - cima" << std::endl;
	std::cout << std::endl;
	std::cout << "h - esquerda     l - direita" << std::endl;
	std::cout << std::endl;
	std::cout << "          j - baixo" << std::endl;

	fd_set fdset;
	FD_ZERO(&fdset);

	timeval timeout;
	timeout.tv_sec = 3;
	timeout.tv_usec = 0;

	FD_SET(STDIN_FILENO, &fdset);
	select(STDIN_FILENO + 1, &fdset, nullptr, nullptr, &timeout);
	if (FD_ISSET(STDIN_FILENO, &fdset))
		getchar();
}

void usage(std::string arg0)
{
	std::cout << "Uso: " << arg0 << " <endereco> <porta>" << std::endl;
}

bool running = true;

struct Options {
	std::string host_addr;
	std::string host_port;

	Options(int argc, char* argv[])
	{
		if (argc != 3) {
			usage(argv[0]);
			exit(1);
		}

		host_addr = argv[1];
		host_port = argv[2];
	}
};

int main(int argc, char* argv[])
{
	Options opt(argc, argv);

	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	addrinfo addr_hint;
	memset(&addr_hint, 0, sizeof(addr_hint));
	addr_hint.ai_family = AF_INET;
	addr_hint.ai_socktype = SOCK_STREAM;
	addr_hint.ai_protocol = IPPROTO_TCP;

	addrinfo* addr_list = nullptr;
	if (int status = getaddrinfo(opt.host_addr.c_str(), opt.host_port.c_str(),
	                             &addr_hint, &addr_list);
	    status != 0) {
		std::cerr << "[ERROR] getaddrinfo(): " << gai_strerror(status)
		          << std::endl;
		close(sock);
		exit(1);
	}

	if (connect(sock, addr_list->ai_addr, addr_list->ai_addrlen) == -1) {
		std::cerr << "[ERROR] connect(): " << std::strerror(errno) << std::endl;
		close(sock);
		exit(1);
	}

	freeaddrinfo(addr_list);

	Map map = net::recv_map(sock);
	auto [pos_x, pos_y] = net::recv_pos(sock);

	graphics::start();
	graphics::render(map, pos_x, pos_y);

	fd_set fdset;
	FD_ZERO(&fdset);

	while (running) {
		FD_SET(STDIN_FILENO, &fdset);
		FD_SET(sock, &fdset);
		select(std::max(STDIN_FILENO, sock) + 1, &fdset, nullptr, nullptr,
		       nullptr);
		if (FD_ISSET(STDIN_FILENO, &fdset)) {
			char c = getchar();
			unsigned short last_x = pos_x, last_y = pos_y;
			switch (c) {
				case 'q':
					running = false;
					break;
				case 'h':
					if (pos_x > 0)
						--pos_x;
					break;
				case 'j':
					if (pos_y < (WIN_HEIGHT - 1))
						++pos_y;
					break;
				case 'k':
					if (pos_y > 0)
						--pos_y;
					break;
				case 'l':
					if (pos_x < (WIN_WIDTH - 1))
						++pos_x;
					break;
				case '?':
					help();
					break;
			}
			if (map.get_tile(pos_x, pos_y) == Tile::WALL) {
				pos_x = last_x;
				pos_y = last_y;
			}
			else
				net::send_pos(sock, pos_x, pos_y);
			graphics::render(map, pos_x, pos_y);
		}

		if (FD_ISSET(sock, &fdset)) {
			std::string tag = net::recv_tag(sock);
			if (tag == "POS") {
				pos_x = net::recv_short(sock);
				pos_y = net::recv_short(sock);
				graphics::render(map, pos_x, pos_y);
			}
			else if (tag == "MSG") {
				std::string message = net::recv_string(sock);
				graphics::print_message(message);
			}
		}
	}

	graphics::stop();

	close(sock);
}
