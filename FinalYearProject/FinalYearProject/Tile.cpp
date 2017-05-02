#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	RandomlyGenerateTileStats();
	SetSpriteOffset();
}

Tile::Tile(TileStats stats)
{
	statistics = stats;
}

Tile::~Tile()
{
}

void Tile::RandomlyGenerateTileStats()
{
	//Topography
	switch (rand() % 7)
	{
	case 0:
		statistics.topography = Topography::DeepSea;
		break;
	case 1:
		statistics.topography = Topography::Depression;
		break;
	case 2:
		statistics.topography = Topography::Hills;
		break;
	case 3:
		statistics.topography = Topography::Impassable;
		break;
	case 4:
		statistics.topography = Topography::Mountainous;
		break;
	case 5:
		statistics.topography = Topography::Plains;
		break;
	case 6:
		statistics.topography = Topography::ShallowSea;
		break;
	}

	//Animal
	switch (rand() % 3)
	{
	case 0:
		statistics.animal = Animal::Consumable;
		break;
	case 1:
		statistics.animal = Animal::Work;
		break;
	case 2:
		statistics.animal = Animal::Unusable;
	}

	//Cliamate
	switch (rand() % 5)
	{
	case 0:
		statistics.climate = Climate::Arid;
		break;
	case 1:
		statistics.climate = Climate::Cold;
		break;
	case 2:
		statistics.climate = Climate::Polar;
		break;
	case 3:
		statistics.climate = Climate::Temperate;
		break;
	case 4:
		statistics.climate = Climate::Tropical;
		break;
	}

	//Fertility
	switch (rand() % 4)
	{
	case 0:
		statistics.fertility = Fertility::High;
		break;
	case 1:
		statistics.fertility = Fertility::Medium;
		break;
	case 2:
		statistics.fertility = Fertility::Low;
		break;
	case 3:
		statistics.fertility = Fertility::Barren;
		break;
	}

	//Plant
	switch (rand() % 4)
	{
	case 0:
		statistics.plant = Plant::FoodCrops;
		break;
	case 1:
		statistics.plant = Plant::HardWood;
		break;
	case 2:
		statistics.plant = Plant::SoftWood;
		break;
	case 3:
		statistics.plant = Plant::Misc;
		break;
	}

	//Mineral
	switch (rand() % 4)
	{
	case 0:
		statistics.mineral = Mineral::HardMetal;
		break;
	case 1:
		statistics.mineral = Mineral::LuxuaryMetal;
		break;
	case 2:
		statistics.mineral = Mineral::SoftMetal;
		break;
	case 3:
		statistics.mineral = Mineral::None;
		break;
	}
}

void Tile::SetSpriteOffset()
{
	switch (statistics.topography)
	{
		case Topography::DeepSea:
			spriteOffset = sf::Vector2i(160, 32);
			break;
		case Topography::ShallowSea:
			spriteOffset = sf::Vector2i(160, 0);
			break;
		case Topography::Impassable:
			spriteOffset = sf::Vector2i(160, 64);
			break;
		case Topography::Depression:
			switch (statistics.plant)
			{
				case Plant::FoodCrops:
					spriteOffset = sf::Vector2i(0, 0);
					break;
				case Plant::SoftWood:
					spriteOffset = sf::Vector2i(0, 32);
					break;
				case Plant::HardWood:
					spriteOffset = sf::Vector2i(0, 64);
					break;
				case Plant::Misc:
					spriteOffset = sf::Vector2i(0, 96);
					break;
			}
			break;
		case Topography::Hills:
			switch (statistics.plant)
			{
			case Plant::FoodCrops:
				spriteOffset = sf::Vector2i(64, 0);
				break;
			case Plant::SoftWood:
				spriteOffset = sf::Vector2i(64, 32);
				break;
			case Plant::HardWood:
				spriteOffset = sf::Vector2i(64, 64);
				break;
			case Plant::Misc:
				spriteOffset = sf::Vector2i(64, 96);
				break;
			}
			break;
		case Topography::Mountainous:
			switch (statistics.plant)
			{
			case Plant::FoodCrops:
				spriteOffset = sf::Vector2i(96, 0);
				break;
			case Plant::SoftWood:
				spriteOffset = sf::Vector2i(96, 32);
				break;
			case Plant::HardWood:
				spriteOffset = sf::Vector2i(96, 64);
				break;
			case Plant::Misc:
				spriteOffset = sf::Vector2i(96, 96);
				break;
			}
			break;
		case Topography::Plains:
			switch (statistics.plant)
			{
			case Plant::FoodCrops:
				spriteOffset = sf::Vector2i(32, 0);
				break;
			case Plant::SoftWood:
				spriteOffset = sf::Vector2i(32, 32);
				break;
			case Plant::HardWood:
				spriteOffset = sf::Vector2i(32, 64);
				break;
			case Plant::Misc:
				spriteOffset = sf::Vector2i(32, 96);
				break;
			}
			break;
	}
}

void Tile::SetClimateColour()
{
	switch (statistics.climate)
	{
		case Climate::Arid:
			climateColour = sf::Vector3i(203, 222, 98);
			break;
		case Climate::Cold:
			climateColour = sf::Vector3i(35, 167, 119);
			break;
		case Climate::Polar:
			climateColour = sf::Vector3i(186, 243, 237);
			break;
		case Climate::Temperate:
			climateColour = sf::Vector3i(15, 198, 52);
			break;
		case Climate::Tropical:
			climateColour = sf::Vector3i(110, 219, 30);
			break;
	}
}

