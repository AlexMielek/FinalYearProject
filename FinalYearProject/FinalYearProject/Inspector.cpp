#include "stdafx.h"
#include "Inspector.h"


Inspector::Inspector()
{
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
