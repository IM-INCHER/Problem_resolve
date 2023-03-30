#pragma once

#include <iostream>

#define MAP_MAX_X 4
#define MAP_MAX_Y 4

using namespace std;

enum MapType
{
	MAP_ROAD,
	MAP_ROCK
};

struct Tile
{
	int index;
	MapType type;
	int distance;
};

class Map
{
private:
	Tile map[MAP_MAX_X][MAP_MAX_Y];

public:
	Map();
	~Map();

	Tile GetTile(int x, int y) { return map[x][y]; }
	Tile SearchTile(int index);
	void MapDrow();
};

