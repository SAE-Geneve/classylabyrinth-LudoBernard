#pragma once

#include <string>

class Tile
{
public:
	Tile(char c);
private:
	enum class TileType : char
	{
		BLOCK = '#',
		EMPTY = '.',
		ENEMY = 'E',
		PLAYER = 'P',
	};
	TileType tile_type_;
};
