#pragma once
#include "Map.h"
#include "GraphicsManager.h"

class GameManager
{
public:
	GameManager();

	//Create a new game manager with a completely random map.
	GameManager(sf::Vector2i mapWidthHeight, std::string spriteSheetFileName);
	
	//Create a new game manager and load in an existing map.
	GameManager(std::string mapFileName);
	~GameManager();

	GraphicsManager* GetGraphicsManager() { return graphicsManager; }

	void ManageInput();

	void Update();

	sf::Vector2i GetMouseClickMapLocation();

private:
	Map* map;

	GraphicsManager* graphicsManager;
};

