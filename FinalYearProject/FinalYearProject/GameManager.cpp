#include "stdafx.h"
#include "GameManager.h"


GameManager::GameManager()
{
}

GameManager::GameManager(std::string mapFileName)
{

}

GameManager::GameManager(sf::Vector2i mapWidthHeight)
{
	map = Map(mapWidthHeight);
}

GameManager::~GameManager()
{
}

void GameManager::Update()
{

}