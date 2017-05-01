#pragma once

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

private:
	Tile* selectedTile;

	bool isOpen = true;
};

