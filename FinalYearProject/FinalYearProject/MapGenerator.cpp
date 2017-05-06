#include "stdafx.h"
#include "MapGenerator.h"
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

MapGenerator::MapGenerator()
{
}


MapGenerator::~MapGenerator()
{
}

void MapGenerator::GenerateMap(MapParams paramaters)
{
	sf::Image LargeMountainImage;
	LargeMountainImage.loadFromFile("MountainBrushL.png");

	sf::Image MediumMountainImage;
	LargeMountainImage.loadFromFile("MountainBrushM.png");

	sf::Image SmallMountainImage;
	LargeMountainImage.loadFromFile("MountainBrushS.png");

	sf::Image MapGenerationImage;
	MapGenerationImage.create(paramaters.mapDimensions.x, paramaters.mapDimensions.y, sf::Color::Transparent);

	//Get Topography settings;
	//Place points as appropriate in red channel.
		//E.g, place initial point. A certain number of points must then be place within a certain range of said point.
		//These points are then used for main height map. Number of initial points depends on islands-pangea.

	//Generate noise map (perlin?) in green channel. Based on red channel will be determine a range of possible heights.

	//Cliamate map in blue channel. Heavily based on other two channels.

	//Take avarages to determine data.
}

int MapGenerator::PerlinNoise(float x, float y)
{

}

float MapGenerator::Lerp(float a, float b, float w)
{
	return (1.0f - w) * a + b * w;
}

float MapGenerator::Gradient(int intx, int inty, float floaty, float floatx, float gradient)
{
	float dx = floatx - (float)intx;
	float dy = floaty - (float)inty;

	return (dx * gradient)
}
