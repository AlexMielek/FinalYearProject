#include "stdafx.h"
#include "Inspector.h"
#include "Tile.h"


Inspector::Inspector()
{
	inspectorView = new sf::View();
	inspectorView->setViewport(sf::FloatRect(0.5f, 0.0f, 0.5f, 1.0f));
	
	if (!textFont.loadFromFile("Roboto-Regular.ttf"))
		int y = 7;
	textToDisplay.setFont(textFont);
	
	textToDisplay.setOutlineColor(sf::Color(238, 233, 233));
	textToDisplay.setFillColor(sf::Color(238, 233, 233));
	textToDisplay.setCharacterSize(10);
	textToDisplay.setStyle(sf::Text::Regular);

	textToDisplay.setPosition(sf::Vector2f(0.0f, 0.0f));
	
	SetTextToDisplay();
}

Inspector::Inspector(sf::RenderWindow* window)
{
	inspectorView = new sf::View(sf::FloatRect(0, 0, window->getSize().x / 4, window->getSize().y));
	inspectorView->setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 1.0f));

	if (!textFont.loadFromFile("Roboto-Regular.ttf"))
		int y = 7;
	textToDisplay.setFont(textFont);

	textToDisplay.setOutlineColor(sf::Color(238, 233, 233));
	textToDisplay.setFillColor(sf::Color(238, 233, 233));
	textToDisplay.setCharacterSize(14);
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
		+ "Animal: " + tileAnimal + "\n"
		+ "Climate: " + tileClimate + "\n"
		+ "Fertility: " + tileFertility + "\n"
		+ "Mineral: " + tileMineral + "\n"
		+ "Plant: " + tilePlant + "\n"
		+ "Topography: " + tileTopography + "\n");
}

void Inspector::DisplayTileStats(Tile* tileToDisplay)
{
	TileStats* statsToDisplay = &tileToDisplay->GetStatistics();

	switch (statsToDisplay->animal)
	{
		case Animal::Consumable:
			tileAnimal = "Consumable";
			break;
		case Animal::Unusable:
			tileAnimal = "Unusable";
			break;
		case Animal::Work:
			tileAnimal = "Work";
			break;
	}

	switch (statsToDisplay->climate)
	{
		case Climate::Arid:
			tileClimate = "Arid";
			break;
		case Climate::Cold:
			tileClimate = "Cold";
			break;
		case Climate::Polar:
			tileClimate = "Polar";
			break;
		case Climate::Temperate:
			tileClimate = "Temperate";
			break;
		case Climate::Tropical:
			tileClimate = "Tropical";
			break;
	}

	switch (statsToDisplay->fertility)
	{
		case Fertility::Barren:
			tileFertility = "Barren";
			break;
		case Fertility::High:
			tileFertility = "High";
			break;
		case Fertility::Low:
			tileFertility = "Low";
			break;
		case Fertility::Medium:
			tileFertility = "Medium";
			break;
	}

	switch (statsToDisplay->mineral)
	{
		case Mineral::HardMetal:
			tileMineral = "HardMetal";
			break;
		case Mineral::LuxuaryMetal:
			tileMineral = "LuxuaryMetal";
			break;
		case Mineral::None:
			tileMineral = "None";
			break;
		case Mineral::SoftMetal:
			tileMineral = "SoftMetal";
			break;
	}

	switch (statsToDisplay->plant)
	{
		case Plant::FoodCrops:
			tilePlant = "FoodCrops";
			break;
		case Plant::SoftWood:
			tilePlant = "SoftWood";
			break;
		case Plant::HardWood:
			tilePlant = "HardWood";
			break;
		case Plant::Misc:
			tilePlant = "Misc";
			break;
	}

	switch (statsToDisplay->topography)
	{
		case Topography::DeepSea:
			tileTopography = "DeepSea";
			break;
		case Topography::ShallowSea:
			tileTopography = "ShallowSea";
			break;
		case Topography::Impassable:
			tileTopography = "Impassable";
			break;
		case Topography::Depression:
			tileTopography = "Depression";
			break;
		case Topography::Hills:
			tileTopography = "Hills";
			break;
		case Topography::Mountainous:
			tileTopography = "Mountainous";
			break;
		case Topography::Plains:
			tileTopography = "Plains";
			break;
	}

	SetTextToDisplay();
}
