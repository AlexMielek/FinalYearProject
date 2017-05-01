#pragma once
#include "Map.h"
#include "GraphicsManager.h"

class GameManager
{
public:
	GameManager();

	//Create a new game manager with a completely random map.
	GameManager(sf::Vector2i mapWidthHeight);
	
	//Create a new game manager and load in an existing map.
	GameManager(std::string mapFileName);
	~GameManager();

	void Update();

private:
	Map map;
	GraphicsManager graphicsManager;
};

