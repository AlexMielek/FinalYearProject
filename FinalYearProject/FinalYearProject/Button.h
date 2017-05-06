#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

class Button
{
public:
	Button();
	Button(std::string buttonText_, sf::Vector2f buttonSize, sf::Vector2f buttonPosition_);
	~Button();

	sf::RectangleShape* GetButtonShape() { return &buttonShape; }

	sf::Text* GetButtonText() { return &buttonText; }

private:
	sf::Text buttonText;

	sf::RectangleShape buttonShape;

	sf::Vector2i buttonPosition;
};

