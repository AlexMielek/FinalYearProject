//Class containing the location of the 'camera' in world space, alongside the view for the main window.
#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

class Camera
{
public:
	Camera();
	Camera(sf::Vector2i widthHeight, sf::Vector2i worldSize);
	~Camera();

	void MoveCamera(sf::Vector2i distanceToMove);

	sf::Vector2i GetPosition() { return worldPosition; }

	sf::View* GetCameraView() { return cameraView; }

private:
	sf::Vector2i dimensions;
	sf::Vector2i worldPosition;
	sf::View* cameraView;
};

