#pragma once

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
	Tile(TileStats stats);
	~Tile();

	TileStats GetStatistics() { return statistics; }

private:
	TileStats statistics;
};

