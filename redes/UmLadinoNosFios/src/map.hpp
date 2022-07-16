#pragma once

#include "net.hpp"

#include <ostream>
#include <tuple>
#include <vector>

class Tile {
 public:
	enum Type {
		FLOOR,
		WALL,
		PLAYER_SPAWN,
		FLAG
	};

 private:
	char tile_char;
	Type type;

 public:
	Tile();
	Tile(char c);

	operator const char() const;
	bool operator==(Type type) const;
	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
};

class Map {
	std::vector<std::vector<Tile>> tiles;

 public:
	Map(std::vector<std::vector<Tile>> tiles);
	Map(const std::string& filename);

	const Tile get_tile(unsigned int x, unsigned int y) const;

	std::tuple<unsigned int, unsigned int> get_spawn_pos() const;

	operator const std::string() const;

	friend std::ostream& operator<<(std::ostream& out, const Map& map);
	friend void net::send_map(int, Map);
};
