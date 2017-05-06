#pragma once
#include <SFML\Graphics.hpp>

class Camera;

class Inspector;

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

	void MoveCamera(sf::Vector2i moveDistance);

	//True = zoom in, false = zoom out;
	void Zoom(bool inOrOut);

	Inspector* GetInspector() { return inspector; }

	Camera* GetCamera() { return camera; }

	float GetCameraZoom() { return mainWindowZoom; }

private:
	Camera* camera;

	Inspector* inspector;

	sf::RenderWindow* mainWindow;

	sf::Sprite spriteSheet;

	sf::Texture spriteSheetTexture;

	std::vector<sf::RectangleShape> climateLayer;

	std::vector<sf::IntRect> textureRects;
	
	float mainWindowZoom = 1.0f;
};

