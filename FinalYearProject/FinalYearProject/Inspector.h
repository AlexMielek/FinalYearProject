#pragma once
#include <SFML\Graphics.hpp>

class Tile;

class Inspector
{
public:
	Inspector();
	Inspector(sf::RenderWindow* window);
	~Inspector();

	void Update();

	void Render();

	void ToggleOpen();

	//Select a tile. If argument is null current selection will be deselected;
	void selectTile(Tile* tileToSelect);

	sf::View* GetInspectorView() { return inspectorView; }

	sf::Text* GetTextToDisplay() { return &textToDisplay; }

	void SetTextToDisplay();

	void DisplayTileStats(Tile* tileToDisplay);

private:
	Tile* selectedTile;

	bool isOpen = true;

	sf::View* inspectorView;

	sf::Vector2i SelectedTileLocation;

	std::string tileTopography = "";
	std::string tileClimate = "";
	std::string tileMineral = "";
	std::string tileAnimal = "";
	std::string tilePlant = "";
	std::string tileFertility = "";

	sf::Text textToDisplay;

	sf::Font textFont;
};

