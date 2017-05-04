#include "stdafx.h"
#include "GraphicsManager.h"
#include "Map.h"
#include "Camera.h"
#include "Inspector.h"

GraphicsManager::GraphicsManager()
{
	mainWindow = new sf::RenderWindow(sf::VideoMode(900, 600), "FinalYearProject");
}

GraphicsManager::GraphicsManager(std::string spriteFileName)
{
	mainWindow = new sf::RenderWindow(sf::VideoMode(900, 600), "FinalYearProject");

	sf::Texture* text = new sf::Texture();
	text->loadFromFile("TerrainLandFoliageNoPlant.png");
	spriteSheet.setTexture(*text);

	camera = new Camera(mainWindow);
	inspector = new Inspector(mainWindow);
}

GraphicsManager::~GraphicsManager()
{
}

void GraphicsManager::Render(Map* map)
{
	mainWindow->clear();
	mainWindow->setView(*camera->GetCameraView());

	sf::Vector2f cameraPosition = (sf::Vector2f)camera->GetPosition();
	sf::Vector2i mapDimensions = map->GetDimensions();

	int position = 0;

	for each (sf::RectangleShape climateColour in climateLayer)
	{
		climateColour.setPosition(climateColour.getPosition() - cameraPosition);
		mainWindow->draw(climateColour);
		position += 1;
	}
	
	std::vector<Tile*> tiles = *map->GetMapTiles();

	position = 0;

	for each (Tile* tile in tiles)
	{
		spriteSheet.setTextureRect(sf::IntRect(tile->GetSpriteOffset(), sf::Vector2i(32, 32)));
		spriteSheet.setPosition(sf::Vector2f((position % mapDimensions.x) * 32, (position / mapDimensions.y) * 32) - cameraPosition);
		mainWindow->draw(spriteSheet);
		position += 1;
	}
	
	mainWindow->setView(*inspector->GetInspectorView());
	mainWindow->draw(*inspector->GetTextToDisplay());

	mainWindow->display();
}

void GraphicsManager::SetUpClimateBackground(Map* map)
{
	int position = 0;
	std::vector<Tile*> tiles = *map->GetMapTiles();
	sf::Vector2i mapDimensions = map->GetDimensions();

	for each (Tile* tile in tiles)
	{
		sf::RectangleShape climateTile(sf::Vector2f(32, 32));
		climateTile.setPosition((position % mapDimensions.x) * 32, (position / mapDimensions.y) * 32);
		climateTile.setFillColor(sf::Color(tile->GetClimateColour()));
		climateLayer.push_back(climateTile);
		position++;
	}
}

void GraphicsManager::MoveCamera(sf::Vector2i moveDistance)
{
	camera->MoveCamera(moveDistance);
}

void GraphicsManager::Zoom(bool inOrOut)
{
	if (!zoomLock)
	{
		if (inOrOut)
		{
			camera->GetCameraView()->zoom(0.8f);
			zoomLock = true;
			return;
		}

		camera->GetCameraView()->zoom(1.2f);
		zoomLock = true;
	}
}
