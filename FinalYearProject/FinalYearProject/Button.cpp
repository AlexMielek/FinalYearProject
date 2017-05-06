#include "stdafx.h"
#include "Button.h"


Button::Button()
{
}

Button::Button(std::string buttonText_, sf::Vector2f buttonSize, sf::Vector2f buttonPosition_)
{
	buttonText.setString(buttonText_);

	buttonShape.setSize(buttonSize);
	buttonShape.setPosition(buttonPosition_)
}

Button::~Button()
{
}
