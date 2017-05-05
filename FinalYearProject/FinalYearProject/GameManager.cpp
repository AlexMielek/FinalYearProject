#include "stdafx.h"
#include "GameManager.h"
#include "Inspector.h"
#include "Camera.h"

GameManager::GameManager()
{
}

GameManager::GameManager(std::string mapFileName)
{

}

GameManager::GameManager(sf::Vector2i mapWidthHeight, std::string spriteSheetFileName)
{
	map = new Map(mapWidthHeight);
	graphicsManager = new GraphicsManager(spriteSheetFileName);
	graphicsManager->SetUpClimateBackground(map);
}

GameManager::~GameManager()
{
}

void GameManager::ManageInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		graphicsManager->MoveCamera(sf::Vector2i(-1, -1));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		graphicsManager->MoveCamera(sf::Vector2i(0, -1));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		graphicsManager->MoveCamera(sf::Vector2i(1, -1));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		graphicsManager->MoveCamera(sf::Vector2i(-1, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		graphicsManager->MoveCamera(sf::Vector2i(1, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		graphicsManager->MoveCamera(sf::Vector2i(-1, 1));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		graphicsManager->MoveCamera(sf::Vector2i(0, 1));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		graphicsManager->MoveCamera(sf::Vector2i(1, 1));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		graphicsManager->Zoom(true);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		graphicsManager->Zoom(false);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		graphicsManager->ToggleZoomLock(false);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		OnMouseClick();
	}
}

void GameManager::Update()
{
	ManageInput();
	graphicsManager->Render(map);
}

void GameManager::OnMouseClick()
{
	sf::RenderWindow* window = graphicsManager->GetMainWindow();

	sf::Vector2i mapDimensions = map->GetDimensions();
	sf::Vector2i mousePositionDesktop = sf::Mouse::getPosition(*window);
	sf::Vector2i mousePosition = (sf::Vector2i)graphicsManager->GetMainWindow()->mapPixelToCoords(mousePositionDesktop, *graphicsManager->GetCamera()->GetCameraView());

	if ((mousePosition.x / 32) < mapDimensions.x && (mousePosition.y / 32) < mapDimensions.y)
	{
		int x = mousePosition.x / 32;
		int y = mousePosition.y / 32;
		int tileAddress = mapDimensions.x * y + x;
		graphicsManager->GetInspector()->DisplayTileStats(map->GetMapTiles()->at(tileAddress));
		return;
	}
	graphicsManager->GetInspector()->DisplayTileStats(new Tile(0));
}