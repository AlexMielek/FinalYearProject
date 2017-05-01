#include "stdafx.h"
#include "Map.h"

Map::Map()
{
}

Map::Map(sf::Vector2i widthHeight)
{
	dimensions = widthHeight;
	for (int y = 0; y < widthHeight.y; y++)
	{
		for (int x = 0; x < widthHeight.x; x++);
		{
			TileStats newStats;
			
			//Topography
			switch (rand() % 7)
			{
				case 0:
					newStats.topography = Topography::DeepSea;
					break;
				case 1:
					newStats.topography = Topography::Depression;
					break;
				case 2:
					newStats.topography = Topography::Hills;
					break;
				case 3:
					newStats.topography = Topography::Impassable;
					break;
				case 4:
					newStats.topography = Topography::Mountainous;
					break;
				case 5:
					newStats.topography = Topography::Plains;
					break;
				case 6:
					newStats.topography = Topography::ShallowSea;
					break;
			}

			//Animal
			switch (rand() % 3)
			{
				case 0:
					newStats.animal = Animal::Consumable;
					break;
				case 1:
					newStats.animal = Animal::Work;
					break;
				case 2:
					newStats.animal = Animal::Unusable;
			}

			//Cliamate
			switch (rand() % 5)
			{
				case 0:
					newStats.climate = Climate::Arid;
					break;
				case 1:
					newStats.climate = Climate::Cold;
					break;
				case 2:
					newStats.climate = Climate::Polar;
					break;
				case 3:
					newStats.climate = Climate::Temperate;
					break;
				case 4:
					newStats.climate = Climate::Tropical;
					break;
			}

			//Fertility
			switch (rand() % 4)
			{
				case 0:
					newStats.fertility = Fertility::High;
					break;
				case 1:
					newStats.fertility = Fertility::Medium;
					break;
				case 2:
					newStats.fertility = Fertility::Low;
					break;
				case 3:
					newStats.fertility = Fertility::Barren;
					break;
			}

			//Plant
			switch (rand() % 4)
			{
			case 0:
				newStats.plant = Plant::FoodCrops;
				break;
			case 1:
				newStats.plant = Plant::HardWood;
				break;
			case 2:
				newStats.plant = Plant::SoftWood;
				break;
			case 3:
				newStats.plant = Plant::Misc;
				break;
			}

			//Mineral
			switch (rand() % 4)
			{
			case 0:
				newStats.mineral = Mineral::HardMetal;
				break;
			case 1:
				newStats.mineral = Mineral::LuxuaryMetal;
				break;
			case 2:
				newStats.mineral = Mineral::SoftMetal;
				break;
			case 3:
				newStats.mineral = Mineral::None;
				break;
			}

			Tile* newTile = new Tile(newStats);

			Tiles.push_back(newTile);
		}
	}
}


Map::~Map()
{
}

void Map::LoadMap()
{

}

void Map::GenerateMap()
{

}
