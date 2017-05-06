#include "stdafx.h"
#include "ComboBox.h"


ComboBox::ComboBox()
{
}

ComboBox::ComboBox(std::string comboBoxName, sf::Vector2f size, sf::Vector2f position)
{
	comboBoxText.setString(comboBoxName);

	comboBoxShape.setSize(size);

	comboBoxShape.setPosition(position);
}

ComboBox::~ComboBox()
{
}
