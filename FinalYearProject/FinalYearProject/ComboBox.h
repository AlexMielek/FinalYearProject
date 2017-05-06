#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\System.hpp>

class ComboBox
{
public:
	ComboBox();
	ComboBox(std::string comboBoxName, sf::Vector2f size, sf::Vector2f position);
	~ComboBox();

	sf::Text* GetText() { return &comboBoxText; }

	sf::RectangleShape* GetShape() { return &comboBoxShape; }

	bool IsChecked() { return checked; }

	void ToggleChecked() { checked = !checked; }

private:

	bool checked;

	sf::Text comboBoxText;

	sf::RectangleShape comboBoxShape;
};

