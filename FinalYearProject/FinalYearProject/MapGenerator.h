#pragma once
#include <SFML\System.hpp>

class Map;

enum LandParam
{
	SmallIslands,
	LargeIslands,
	SmallContinents,
	LargeContinents,
	Pangea
};

enum WaterParam
{
	Rare,
	Low,
	Medium,
	High
};

struct MapParams
{
	sf::Vector2i mapDimensions;
	LandParam land;
	WaterParam water;
	int height;
};

class MapGenerator
{
public:
	MapGenerator();
	~MapGenerator();

	void GenerateMap(MapParams paramaters);

	Map* GetGeneratedMap() { return map; }

private:
	int PerlinNoise(float x, float y);

	float Lerp(float a, float b, float w);

	float Gradient(int intx, int inty, float floaty, float floatx, float gradient);

	Map* map;
};

