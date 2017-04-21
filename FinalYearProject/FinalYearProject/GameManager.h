#pragma once
#include "Map.h"
#include "GraphicsManager.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update();

private:
	Map map;
	GraphicsManager graphicsManager;
};

