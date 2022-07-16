#include "net.hpp"

#include "map.hpp"

#include <arpa/inet.h>
#include <iomanip>
#include <iostream>
#include <sys/socket.h>

void net::send_tag(int sock, const std::string& tag)
{
	if (tag.size() != 3)
		throw net::unexpected_tag_error(tag);

	send(sock, tag.data(), 3, 0);
}

std::string net::recv_tag(int sock)
{
	char buf[4] = {0};
	recv(sock, buf, 3, 0);
	std::string tag {buf};

	return tag;
}

std::string net::recv_tag(int sock, const std::string& expected_tag)
{
	std::string tag = net::recv_tag(sock);

	if (tag != expected_tag)
		throw net::unexpected_tag_error(tag);

	return tag;
}

void net::send_short(int sock, unsigned short value)
{
	value = htons(value);
	send(sock, &value, sizeof(value), 0);
}

unsigned short net::recv_short(int sock)
{
	unsigned short value;
	recv(sock, &value, sizeof(value), 0);
	return ntohs(value);
}

void net::send_string(int sock, const std::string& text)
{
	send_short(sock, text.size());

	unsigned int sent = 0;
	while (sent < text.size()) {
		unsigned int sent_now =
		    send(sock, &text.data()[sent], text.size() - sent, 0);

		if (sent_now == -1u) {
			throw std::runtime_error("send()");
		}

		sent += sent_now;
	}
}

std::string net::recv_string(int sock)
{
	unsigned int size = recv_short(sock);

	char* buf = (char*)calloc(sizeof(char), size);

	unsigned int received = 0;
	while (received < size) {
		int received_now = recv(sock, &buf[received], size - received, 0);
		if (received_now == -1) {
			throw std::runtime_error("recv()");
		}

		received += received_now;
	}

	std::string text(buf);
	free(buf);

	return text;
}

void net::send_message(int sock, const std::string& text)
{
	send_tag(sock, "MSG");
	send_string(sock, text);
}

std::string net::recv_message(int sock)
{
	net::recv_tag(sock, "MSG");
	return recv_string(sock);
}

void net::send_map(int sock, Map map)
{
	send_tag(sock, "MAP");
	send_short(sock, map.tiles.size());

	for (const auto& row : map.tiles) {
		std::string row_text;
		for (const auto& tile : row)
			if (tile == '@')
				row_text += ' ';
			else
				row_text += tile;

		send_string(sock, row_text);
	}
}

Map net::recv_map(int sock)
{
	std::vector<std::vector<Tile>> tiles;
	std::string tag = net::recv_tag(sock, "MAP");

	unsigned short rows = recv_short(sock);
	for (unsigned int row_n = 0; row_n < rows; ++row_n) {
		tiles.emplace_back();

		std::string row = recv_string(sock);
		for (auto tile : row)
			tiles[row_n].push_back(Tile(tile));
	}

	return Map(tiles);
}

void net::send_pos(int sock, unsigned int x, unsigned int y)
{
	send_tag(sock, "POS");
	send_short(sock, x);
	send_short(sock, y);
}

std::tuple<unsigned int, unsigned int> net::recv_pos(int sock)
{
	net::recv_tag(sock, "POS");
	unsigned short x = recv_short(sock);
	unsigned short y = recv_short(sock);

	return std::tuple(x, y);
}
