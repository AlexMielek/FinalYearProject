#include "stdafx.h"
#include "GraphicsManager.h"
#include "Map.h"


GraphicsManager::GraphicsManager()
{
	mainWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "FinalYearProject");
}

GraphicsManager::GraphicsManager(std::string spriteFileName)
{
	mainWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "FinalYearProject");
	sf::Texture* text = new sf::Texture();
	if (text->loadFromFile("TerrainLandFoliageNoPlant.png"))
		int ohNo = 0;
	//spriteSheetTexture = text;
	spriteSheet.setTexture(*text);
}

GraphicsManager::~GraphicsManager()
{
}

void GraphicsManager::Render(Map* map)
{
	mainWindow->clear();
	
	for each (sf::RectangleShape climateColour in climateLayer)
	{
		mainWindow->draw(climateColour);
	}
	
	std::vector<Tile*> tiles = *map->GetMapTiles();

	int position = 0;
	for each (Tile* tile in tiles)
	{
		int y = map->GetDimensions().y;
		spriteSheet.setTextureRect(sf::IntRect(tile->GetSpriteOffset(), sf::Vector2i(32, 32)));
		spriteSheet.setPosition((position % map->GetDimensions().x) * 32, (position / y) * 32);
		mainWindow->draw(spriteSheet);
		position += 1;
	}
	
	mainWindow->display();
}

void GraphicsManager::SetUpClimateBackground(Map* map)
{
	int position = 0;
	std::vector<Tile*> tiles = *map->GetMapTiles();
	for each (Tile* tile in tiles)
	{
		int y = map->GetDimensions().y;
		sf::RectangleShape bg(sf::Vector2f(32, 32));
		bg.setPosition((position % map->GetDimensions().x) * 32, (position / y) * 32);
		bg.setFillColor(sf::Color(tile->GetClimateColour()));
		climateLayer.push_back(bg);
		position++;
	}
}
