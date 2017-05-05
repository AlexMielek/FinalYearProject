#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

enum Topography
{
	Impassable,
	Mountainous,
	Hills,
	Plains,
	Depression,
	ShallowSea,
	DeepSea
};

enum Climate
{
	Tropical,
	Arid,
	Temperate,
	Cold, 
	Polar,
};

enum Mineral
{
	HardMetal,
	SoftMetal,
	LuxuaryMetal,
	None
};

enum Animal
{
	Consumable,
	Work,
	Unusable
};

enum Plant
{
	HardWood,
	SoftWood,
	FoodCrops,
	Misc
};

enum Fertility
{
	High,
	Medium,
	Low,
	Barren
};

struct TileStats
{
	Topography topography;
	Climate climate;
	Mineral mineral;
	Animal animal;
	Plant plant;
	Fertility fertility;
};

class Tile
{
public:
	Tile();
	Tile(int leaveBlank);
	Tile(TileStats stats);
	~Tile();

	TileStats GetStatistics() { return statistics; }

	sf::Vector2i GetSpriteOffset() { return spriteOffset; }

	sf::Color GetClimateColour() { return climateColour; }

	void RandomlyGenerateTileStats();

private:
	TileStats statistics;

	sf::Vector2i spriteOffset;

	sf::Color climateColour;

	void SetSpriteOffset();

	void SetClimateColour();
};

