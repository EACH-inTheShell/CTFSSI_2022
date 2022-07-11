#include <arpa/inet.h>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <memory.h>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <vector>

class Tile {
	char tile_char;

 public:
	Tile(char c) : tile_char(c)
	{
		// TODO: Store more information for every char
	}

	friend std::ostream& operator<<(std::ostream& out, const Tile& tile)
	{
		out << tile.tile_char;
		return out;
	}
};

class Map {
	std::vector<std::vector<Tile>> map;

 public:
	Map(const std::string& filename)
	{
		std::ifstream file(filename);

		std::string line;
		while (std::getline(file, line)) {
			std::vector<Tile> row;
			for (char c : line)
				row.emplace_back(c);
			map.push_back(row);
		}

		file.close();
	}

	friend std::ostream& operator<<(std::ostream& out, const Map& map)
	{
		for (auto& row : map.map) {
			for (auto tile : row)
				out << tile;
			out << std::endl;
		}
		return out;
	}
};

struct Options {
	int port = 47000;
	int listen = 20;
	std::string map_file = "./map.txt";

	Options() = default;

	Options(int argc, char* argv[]) {
		// TODO: parse arguments
	}
};

Options option;

void handle_client(int sock)
{
	Map map(option.map_file);

	std::cout << "[INFO] Loaded map:\n" << map;

	// TODO: Logic...
	send(sock, "game", 4, 0);
	close(sock);
}

int main(int argc, char* argv[])
{
	option = Options(argc, argv);
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (sock == -1) {
		std::cerr << "[ERROR] socket(): " << strerror(errno) << std::endl;
		return errno;
	}

	sockaddr_in hint;
	memset(&hint, 0, sizeof(hint));
	hint.sin_family = AF_INET;
	hint.sin_addr.s_addr = INADDR_ANY;
	hint.sin_port = htons(option.port);

	if (bind(sock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint)) == -1) {
		std::cerr << "[ERROR] bind(): " << strerror(errno) << std::endl;
		return errno;
	}

	listen(sock, option.listen);

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
