#include "stdafx.h"
#include "Map.h"

Map::Map()
{
}

Map::Map(sf::Vector2i widthHeight)
{
	dimensions = widthHeight;
	//int y = 0;
	//int x = 0;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			Tile* newTile = new Tile();

			Tiles.push_back(newTile);
		}
	}
}


Map::~Map()
{
}

void Map::LoadMap()
{

}

void Map::GenerateMap()
{

}
