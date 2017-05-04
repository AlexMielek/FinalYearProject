#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
	worldPosition = sf::Vector2i(0, 0);
}

Camera::Camera(sf::Vector2i widthHeight, sf::Vector2i worldSize)
{
	dimensions = widthHeight;
	worldPosition = sf::Vector2i(worldSize.x / 2, worldSize.y / 2);
}


Camera::~Camera()
{
}

void Camera::MoveCamera(sf::Vector2i distanceToMove)
{
	worldPosition += distanceToMove;
}
