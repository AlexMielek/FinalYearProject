#include "stdafx.h"
#include "Slider.h"


Slider::Slider()
{
}

Slider::Slider(int lowerBound_, int upperBound_, sf::Vector2i sliderPosition_, std::string valueName_)
{
	lowerBound = lowerBound_;
	upperBound = upperBound_;
	sliderPosition = sliderPosition_;

	valueName.setString(valueName_);
	valueValue.setString(std::to_string(lowerBound));
}

void Slider::SliderSetup()
{
	sliderLine.setSize(sf::Vector2f(300, 10));
	sliderLine.setPosition(sf::Vector2f(sliderPosition));

	sliderBox.setSize(sf::Vector2f(20, 32));
	sliderLine.setPosition(sf::Vector2f(sliderPosition));
}


Slider::~Slider()
{
}

bool Slider::CheckIfClicked()
{

}

void Slider::MoveSlider()
{
	if (CheckIfClicked())
	{
		if ((sf::Vector2i)sf::Mouse::getPosition() != lastMouseScreenPosition)
		{
			int moveDistance = (sf::Mouse::getPosition() - lastMouseScreenPosition).x;
			sliderPosition += sf::Vector2i(moveDistance, 0);
			if (sliderPosition.x > upperBound)
				sliderPosition.x = upperBound;
			else if (sliderPosition.x < lowerBound)
				sliderPosition.y = lowerBound;
		}
	}
}
