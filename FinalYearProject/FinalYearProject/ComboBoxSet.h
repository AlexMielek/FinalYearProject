#pragma once
#include "ComboBox.h"
#include <vector>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

class ComboBoxSet
{
public:
	ComboBoxSet();
	~ComboBoxSet();

	void AddComboBox(std::string comboBoxName, sf::Vector2f size, sf::Vector2f position);

	std::vector<ComboBox*>* GetBoxes() { return &comboBoxes; }

private:

	std::vector<ComboBox*> comboBoxes;
};

