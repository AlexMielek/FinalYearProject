#pragma once
#include <SFML\Graphics.hpp>

class GraphicsManager
{
public:
	GraphicsManager();
	~GraphicsManager();

	void Render();

private:
	sf::Sprite spriteSheet;

	sf::Texture spriteSheetTexture;
};

