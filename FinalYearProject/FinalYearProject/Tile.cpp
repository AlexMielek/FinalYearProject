#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	RandomlyGenerateTileStats();
	SetSpriteOffset();
	SetClimateColour();
}

Tile::Tile(int leaveBlank)
{

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
	//Climate
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

	//Topography
	switch (rand() % 7)
	{
	case 0:
		statistics.topography = Topography::DeepSea;
		statistics.animal = Animal::Unusable;
		statistics.fertility = Fertility::Barren;
		statistics.mineral = Mineral::None;
		statistics.plant = Plant::Misc;
		return;
	case 1:
		statistics.topography = Topography::Depression;
		break;
	case 2:
		statistics.topography = Topography::Hills;
		break;
	case 3:
		statistics.topography = Topography::Impassable;
		statistics.animal = Animal::Unusable;
		statistics.fertility = Fertility::Barren;
		statistics.mineral = Mineral::None;
		statistics.plant = Plant::Misc;
		return;
	case 4:
		statistics.topography = Topography::Mountainous;
		break;
	case 5:
		statistics.topography = Topography::Plains;
		break;
	case 6:
		statistics.topography = Topography::ShallowSea;
		statistics.animal = Animal::Unusable;
		statistics.fertility = Fertility::Barren;
		statistics.mineral = Mineral::None;
		statistics.plant = Plant::Misc;
		return;
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
			spriteOffsetAddress = 0;
			break;
		case Topography::ShallowSea:
			spriteOffsetAddress = 1;
			break;
		case Topography::Impassable:
			spriteOffsetAddress = 2;
			break;
		case Topography::Depression:
			switch (statistics.plant)
			{
				case Plant::FoodCrops:
					spriteOffsetAddress = 3;
					break;
				case Plant::SoftWood:
					spriteOffsetAddress = 4;
					break;
				case Plant::HardWood:
					spriteOffsetAddress = 5;
					break;
				case Plant::Misc:
					spriteOffsetAddress = 6;
					break;
			}
			break;
		case Topography::Hills:
			switch (statistics.plant)
			{
			case Plant::FoodCrops:
				spriteOffsetAddress = 7;
				break;
			case Plant::SoftWood:
				spriteOffsetAddress = 8;
				break;
			case Plant::HardWood:
				spriteOffsetAddress = 9;
				break;
			case Plant::Misc:
				spriteOffsetAddress = 10;
				break;
			}
			break;
		case Topography::Mountainous:
			switch (statistics.plant)
			{
			case Plant::FoodCrops:
				spriteOffsetAddress = 11;
				break;
			case Plant::SoftWood:
				spriteOffsetAddress = 12;
				break;
			case Plant::HardWood:
				spriteOffsetAddress = 13;
				break;
			case Plant::Misc:
				spriteOffsetAddress = 14;
				break;
			}
			break;
		case Topography::Plains:
			switch (statistics.plant)
			{
			case Plant::FoodCrops:
				spriteOffsetAddress = 15;
				break;
			case Plant::SoftWood:
				spriteOffsetAddress = 16;
				break;
			case Plant::HardWood:
				spriteOffsetAddress = 17;
				break;
			case Plant::Misc:
				spriteOffsetAddress = 18;
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
			climateColour = sf::Color(203, 222, 98);
			break;
		case Climate::Cold:
			climateColour = sf::Color(35, 167, 119);
			break;
		case Climate::Polar:
			climateColour = sf::Color(186, 243, 237);
			break;
		case Climate::Temperate:
			climateColour = sf::Color(15, 198, 52);
			break;
		case Climate::Tropical:
			climateColour = sf::Color(110, 219, 30);
			break;
	}
}

