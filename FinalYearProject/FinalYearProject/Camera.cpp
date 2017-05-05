#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
	worldPosition = sf::Vector2i(0, 0);
	cameraView = new sf::View();
	cameraView->setViewport(sf::FloatRect(0.0f, 0.0f, 0.75f, 1.0f));
}

Camera::Camera(sf::RenderWindow* window)
{
	worldPosition = sf::Vector2i(0, 0);
	cameraView = new sf::View(sf::FloatRect(0, 0, (window->getSize().x / 4) * 3, window->getSize().y));
	cameraView->setViewport(sf::FloatRect(0.0f, 0.0f, 0.75f, 1.0f));
	//cameraView->setCenter(0, 0);
}

Camera::Camera(sf::Vector2i widthHeight, sf::Vector2i worldSize)
{
	dimensions = widthHeight;
	worldPosition = sf::Vector2i(worldSize.x / 2, worldSize.y / 2);
	cameraView = new sf::View(sf::FloatRect(0, 0, (worldSize.x / 4) * 3, worldSize.y));
	cameraView->setViewport(sf::FloatRect(0.0f, 0.0f, 0.75f, 1.0f));
}


Camera::~Camera()
{
}

void Camera::MoveCamera(sf::Vector2i distanceToMove)
{
	worldPosition += distanceToMove;
}
