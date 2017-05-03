#pragma once
#include <SFML\Graphics.hpp>

class Camera;

class Map;

class GraphicsManager
{
public:
	GraphicsManager();
	GraphicsManager(std::string spriteFileName);
	~GraphicsManager();

	sf::RenderWindow* GetMainWindow() { return mainWindow; }

	void Render(Map* map);

	void SetUpClimateBackground(Map* map);

private:
	Camera* camera;

	sf::RenderWindow* mainWindow;

	sf::Sprite spriteSheet;

	sf::Texture spriteSheetTexture;

	std::vector<sf::RectangleShape> climateLayer;
};

