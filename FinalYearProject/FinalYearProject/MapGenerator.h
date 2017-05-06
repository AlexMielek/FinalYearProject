#pragma once

class Map;

class MapGenerator
{
public:
	MapGenerator();
	~MapGenerator();

	void GenerateMap();

	Map* GetGeneratedMap() { return map; }

private:
	Map* map;
};

