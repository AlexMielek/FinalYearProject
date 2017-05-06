#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

class Slider
{
public:
	Slider();
	Slider(int lowerBound_, int upperBound_, sf::Vector2i sliderPosition_, std::string valueName_);
	~Slider();

	void SliderSetup();

	bool CheckIfClicked();
	
	void MoveSlider();

	sf::RectangleShape* GetSliderBox() { return &sliderBox; }
	sf::RectangleShape* GetSliderLine() { return &sliderLine; }
	sf::Vector2i GetSliderPosition() { return sliderPosition; }
	int GetCurrentValue() { return currentValue; }

private:
	int lowerBound;
	int upperBound;
	int currentValue;
	
	sf::Vector2i sliderPosition;
	sf::Vector2i lastMouseScreenPosition;

	sf::RectangleShape sliderBox;
	sf::RectangleShape sliderLine;

	sf::Text valueName;
	sf::Text valueValue;
};

