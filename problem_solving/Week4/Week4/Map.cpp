#include "Map.h"

Map::Map()
{
	int index = 0;
	for (int i = 0; i < MAP_MAX_X; i++)
	{
		for (int j = 0; j < MAP_MAX_Y; j++)
		{
			map[i][j].index = index;
			map[i][j].type = MAP_ROAD;
			map[i][j].distance;
			index++;
		}
	}
}

Map::~Map()
{
}


Tile Map::SearchTile(int index)
{
	for (int i = 0; i < MAP_MAX_X; i++)
	{
		for (int j = 0; j < MAP_MAX_Y; j++)
		{
			if (index = map[i][j].index)
				return 	map[i][j];
		}
	}
}

void Map::MapDrow()
{
	for (int i = 0; i < MAP_MAX_X; i++)
	{
		for (int j = 0; j < MAP_MAX_Y; j++)
		{
			cout << "    " << map[i][j].index;
		}
		cout << endl;
		cout << endl;
	}
}
