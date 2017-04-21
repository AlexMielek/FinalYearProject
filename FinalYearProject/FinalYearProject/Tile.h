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

};

enum Animal
{
	Consumable,
	Work
};

enum Plant
{
	HardWood,
	SoftWood,
	FoodCrops
};

enum Fertility
{
	High,
	Medium,
	Low
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
	~Tile();

	TileStats GetStatistics() { return statistics; }

private:
	TileStats statistics;
};

