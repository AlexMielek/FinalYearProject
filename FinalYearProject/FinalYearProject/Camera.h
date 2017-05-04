#pragma once
#include <SFML\System.hpp>

class Camera
{
public:
	Camera();
	Camera(sf::Vector2i widthHeight, sf::Vector2i worldSize);
	~Camera();

	void MoveCamera(sf::Vector2i distanceToMove);

	sf::Vector2i GetPosition() { return worldPosition; }

private:
	sf::Vector2i dimensions;
	sf::Vector2i worldPosition;
};

