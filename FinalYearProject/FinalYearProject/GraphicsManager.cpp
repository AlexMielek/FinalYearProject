#include "stdafx.h"
#include "GraphicsManager.h"
#include "Map.h"
#include "Camera.h"

GraphicsManager::GraphicsManager()
{
	mainWindow = new sf::RenderWindow(sf::VideoMode(900, 600), "FinalYearProject");
}

GraphicsManager::GraphicsManager(std::string spriteFileName)
{
	mainWindow = new sf::RenderWindow(sf::VideoMode(900, 600), "FinalYearProject");
	sf::Texture* text = new sf::Texture();
	if (text->loadFromFile("TerrainLandFoliageNoPlant.png"))
		int ohNo = 0;
	//spriteSheetTexture = text;
	spriteSheet.setTexture(*text);
	camera = new Camera();

	mainView = new sf::View();
	mainView->setViewport(sf::FloatRect(0.0f, 0.0f, 0.75f, 1.0f));

	inspectorView = new sf::View();
	inspectorView->setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 1.0f));
}

GraphicsManager::~GraphicsManager()
{
}

void GraphicsManager::Render(Map* map)
{
	mainWindow->clear();
	mainWindow->setView(*mainView);

	int position = 0;

	for each (sf::RectangleShape climateColour in climateLayer)
	{
		climateColour.setPosition(climateColour.getPosition() - (sf::Vector2f)camera->GetPosition());
		mainWindow->draw(climateColour);
		position += 1;
	}
	
	std::vector<Tile*> tiles = *map->GetMapTiles();

	position = 0;

	for each (Tile* tile in tiles)
	{
		int y = map->GetDimensions().y;
		spriteSheet.setTextureRect(sf::IntRect(tile->GetSpriteOffset(), sf::Vector2i(32, 32)));
		spriteSheet.setPosition(sf::Vector2f((position % map->GetDimensions().x) * 32, (position / y) * 32) - (sf::Vector2f)camera->GetPosition());
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

void GraphicsManager::MoveCamera(sf::Vector2i moveDistance)
{
	camera->MoveCamera(moveDistance);
}

void GraphicsManager::Zoom(bool inOrOut)
{
	if (!jfbsdakbnfdkaj)
	{
		if (inOrOut)
		{
			mainWindowZoom -= 0.2f;
			mainView->zoom(0.8f);
			jfbsdakbnfdkaj = true;
			return;
		}

		mainWindowZoom += 0.2f;
		mainView->zoom(1.2f);
		jfbsdakbnfdkaj = true;
	}
}
