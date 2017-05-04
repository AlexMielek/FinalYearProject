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

	void MoveCamera(sf::Vector2i moveDistance);

	//True = zoom in, false = zoom out;
	void Zoom(bool inOrOut);
	bool jfbsdakbnfdkaj = false;
private:
	Camera* camera;

	sf::RenderWindow* mainWindow;

	sf::Sprite spriteSheet;

	sf::Texture spriteSheetTexture;

	std::vector<sf::RectangleShape> climateLayer;

	sf::View* mainView;
	float mainWindowZoom = 1.0f;
	

	sf::View* inspectorView;
};

