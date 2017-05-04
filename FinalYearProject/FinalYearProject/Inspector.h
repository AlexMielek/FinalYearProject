#pragma once
#include <SFML\Graphics.hpp>

class Tile;

class Inspector
{
public:
	Inspector();
	~Inspector();

	void Update();

	void Render();

	void ToggleOpen();

	//Select a tile. If argument is null current selection will be deselected;
	void selectTile(Tile* tileToSelect);

	sf::View* GetInspectorView() { return inspectorView; }

private:
	Tile* selectedTile;

	bool isOpen = true;

	sf::View* inspectorView;
};

