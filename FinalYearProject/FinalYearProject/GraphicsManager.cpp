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
	sf::Texture text;
	if (text.loadFromFile("TerrainLandFoliageNoPlant.png"))
		int ohNo = 0;
	spriteSheetTexture = text;
	spriteSheet.setTexture(spriteSheetTexture);

}

GraphicsManager::~GraphicsManager()
{
}

void GraphicsManager::Render(Map* map)
{
	mainWindow->clear();

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
	
	/*for (int y = 0; y < map->GetDimensions().y; y++)
	{
		for (int x = 0; x < map->GetDimensions().x; x++)
		{
			spriteSheet.setTextureRect(sf::IntRect(tiles[y * map->GetDimensions().x + x]->GetSpriteOffset(), sf::Vector2i(32, 32)));
			spriteSheet.setPosition(x * 32, y * 32);
			mainWindow->draw(spriteSheet);
		}
	}*/
	//Add render.

	mainWindow->display();
}
