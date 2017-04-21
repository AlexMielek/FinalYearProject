#pragma once
#include <SFML\System.hpp>
#include <vector>
#include "Tile.h"

class Map
{
public:
	Map();
	~Map();

	std::vector<Tile*>* GetMapTiles() { return &Tiles; }

	sf::Vector2i GetDimensions() { return dimensions; }

	void LoadMap();

	void GenerateMap();

private:
	//x = width, y = height.
	sf::Vector2i dimensions;

	//Organized in rows.
	std::vector<Tile*> Tiles;
};

