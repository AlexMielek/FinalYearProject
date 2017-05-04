#include "stdafx.h"
#include "Inspector.h"


Inspector::Inspector()
{
	inspectorView = new sf::View();
	inspectorView->setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 1.0f));
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
