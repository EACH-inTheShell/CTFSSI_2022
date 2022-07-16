#include "map.hpp"

#include <fstream>

Tile::Tile() : Tile(' ') { }

Tile::Tile(char c) : tile_char(c)
{
	switch (c) {
		case '#':
			type = WALL;
			break;
		case '@':
			type = PLAYER_SPAWN;
			break;
		case 'F':
			type = FLAG;
			break;
		case ' ':
		default:
			type = FLOOR;
	}
}

Tile::operator const char() const
{
	return tile_char;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
	out << tile.tile_char;
	return out;
}

Map::Map(std::vector<std::vector<Tile>> tiles) : tiles(tiles) { }

Map::Map(const std::string& filename)
{
	std::ifstream file(filename);

	std::string line;
	while (std::getline(file, line)) {
		std::vector<Tile> row;
		for (char c : line)
			row.emplace_back(c);
		tiles.push_back(row);
	}

	file.close();
}

const Tile Map::get_tile(unsigned int x, unsigned int y) const
{
	if (y < 0 || y >= tiles.size())
		return Tile();

	auto row = tiles[y];
	if (x < 0 || x >= row.size())
		return Tile();

	return row[x];
}

std::tuple<unsigned int, unsigned int> Map::get_spawn_pos() const
{
	for (unsigned int y = 0; y < tiles.size(); ++y) {
		const auto& row = tiles[y];
		for (unsigned int x = 0; x < row.size(); ++x)
			if (row[x] == Tile::PLAYER_SPAWN)
				return std::tuple(x, y);
	}

	return std::tuple(1u, 1u);
}

bool Tile::operator==(Type type) const
{
	return this->type == type;
}

Map::operator const std::string() const
{
	std::string text;
	for (auto& row : tiles) {
		for (auto tile : row)
			text += tile;
	}
	return text;
}

std::ostream& operator<<(std::ostream& out, const Map& map)
{
	for (auto& row : map.tiles) {
		for (auto tile : row)
			out << tile;
		out << std::endl;
	}
	return out;
}
