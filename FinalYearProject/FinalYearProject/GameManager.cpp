#include "stdafx.h"
#include "GameManager.h"


GameManager::GameManager()
{
}

GameManager::GameManager(std::string mapFileName)
{

}

GameManager::GameManager(sf::Vector2i mapWidthHeight, std::string spriteSheetFileName)
{
	map = Map(mapWidthHeight);
	graphicsManager = GraphicsManager(spriteSheetFileName);
	graphicsManager.SetUpClimateBackground(&map);
}

GameManager::~GameManager()
{
}

void GameManager::Update()
{
	graphicsManager.Render(&map);
}