#include "stdafx.h"
#include "Inspector.h"


Inspector::Inspector()
{
	inspectorView = new sf::View();
	inspectorView->setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 1.0f));
	
	if (!textFont.loadFromFile("Roboto-Regular.ttf"))
		int y = 7;
	textToDisplay.setFont(textFont);
	
	textToDisplay.setOutlineColor(sf::Color(238, 233, 233));
	textToDisplay.setFillColor(sf::Color(238, 233, 233));
	textToDisplay.setCharacterSize(64);
	textToDisplay.setStyle(sf::Text::Regular);

	textToDisplay.setPosition(sf::Vector2f(0.0f, 0.0f));
	
	SetTextToDisplay();
}


Inspector::~Inspector()
{
}

void Inspector::Update()
{
	if (isOpen)
		Render();
}

void Inspector::Render()
{
	if (selectedTile = nullptr)
	{

	}
	else
	{

	}
}

void Inspector::ToggleOpen()
{
	isOpen = !isOpen;
}

void Inspector::selectTile(Tile* tileToSelect)
{
	selectedTile = tileToSelect;
}

void Inspector::SetTextToDisplay()
{
	textToDisplay.setString("Tile Coords: " + std::to_string(SelectedTileLocation.x) + ", "
		+ std::to_string(SelectedTileLocation.y) + "\n"
		+ "Mineral: " + tileAnimal + "\n"
		+ "Climate: " + tileClimate + "\n"
		+ "Fertility: " + tileFertility + "\n"
		+ "Mineral: " + tileMineral + "\n"
		+ "Plant: " + tilePlant + "\n"
		+ "Topography: " + tileTopography + "\n");
}
