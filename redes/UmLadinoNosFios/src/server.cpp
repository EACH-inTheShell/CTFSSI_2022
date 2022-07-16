#include "map.hpp"
#include "net.hpp"

#include <arpa/inet.h>
#include <errno.h>
#include <iomanip>
#include <iostream>
#include <memory.h>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>

const std::string flag = "eits{flag}";

struct Options {
	static constexpr int port = 47000;
	static constexpr int listen = 20;
	static constexpr std::string_view map_file = "./map.txt";
};

void handle_client(int sock)
{
	Map map((std::string(Options::map_file)));

	std::cout << "[INFO] Loaded map:\n" << map;

	net::send_map(sock, map);

	auto [last_x, last_y] = map.get_spawn_pos();
	net::send_pos(sock, last_x, last_y);

	try {
		while (true) {
			auto [x, y] = net::recv_pos(sock);

			Tile t = map.get_tile(x, y);

			if (t == Tile::FLAG)
				net::send_message(sock, flag);

			else if (t == Tile::WALL) {
				net::send_pos(sock, last_x, last_y);
				continue;
			}

			last_x = x;
			last_y = y;
		}
	}
	catch (net::unexpected_tag_error e) {
		std::cerr << "[ERROR] " << e << std::endl;
	}

	close(sock);
}

int main()
{
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (sock == -1) {
		std::cerr << "[ERROR] socket(): " << strerror(errno) << std::endl;
		return errno;
	}

	sockaddr_in hint;
	memset(&hint, 0, sizeof(hint));
	hint.sin_family = AF_INET;
	hint.sin_addr.s_addr = INADDR_ANY;
	hint.sin_port = htons(Options::port);

	if (bind(sock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint)) == -1) {
		std::cerr << "[ERROR] bind(): " << strerror(errno) << std::endl;
		return errno;
	}

	listen(sock, Options::listen);

	while (true) {
		int client_sock = accept(sock, nullptr, nullptr);
		std::cout << "[INFO] Attending new client" << std::endl;

		if (client_sock == -1) {
			std::cerr << "[ERROR] accept(): " << strerror(errno) << std::endl;
			return errno;
		}

		std::thread t(handle_client, client_sock);
		t.detach();
	}
}
