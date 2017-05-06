#include "stdafx.h"
#include "ComboBoxSet.h"


ComboBoxSet::ComboBoxSet()
{
}

void ComboBoxSet::AddComboBox(std::string comboBoxName, sf::Vector2f size, sf::Vector2f position)
{
	comboBoxes.push_back(new ComboBox(comboBoxName, size, position));
}

ComboBoxSet::~ComboBoxSet()
{
}
