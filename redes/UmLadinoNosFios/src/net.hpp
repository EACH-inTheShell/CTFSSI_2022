#pragma once

#include <arpa/inet.h>
#include <exception>
#include <iomanip>
#include <ostream>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <tuple>

class Map;

namespace net {
	class unexpected_tag_error : std::runtime_error {
		const std::string tag;

	 public:
		unexpected_tag_error(const std::string& tag) :
		    std::runtime_error("Unexpected tag " + tag), tag(tag)
		{
		}

		friend std::ostream& operator<<(std::ostream& out,
		                                const unexpected_tag_error e)
		{
			out << "Unexpected tag " << std::quoted(e.tag);
			return out;
		}
	};

	void send_tag(int sock, const std::string& expected_tag);
	std::string recv_tag(int sock);
	std::string recv_tag(int sock, const std::string& expected_tag);

	void send_short(int sock, unsigned short value);
	unsigned short recv_short(int sock);

	void send_string(int sock, const std::string& text);
	std::string recv_string(int sock);

	void send_message(int sock, const std::string& text);
	std::string recv_message(int sock);

	void send_map(int sock, Map map);
	Map recv_map(int sock);

	void send_pos(int sock, unsigned int x, unsigned int y);
	std::tuple<unsigned int, unsigned int> recv_pos(int sock);
}
