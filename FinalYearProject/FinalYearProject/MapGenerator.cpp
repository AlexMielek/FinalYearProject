#include "stdafx.h"
#include "MapGenerator.h"


MapGenerator::MapGenerator()
{
}


MapGenerator::~MapGenerator()
{
}

void MapGenerator::GenerateMap()
{
	//Get Topography settings;
	//Place points as appropriate in red channel.
		//E.g, place initial point. A certain number of points must then be place within a certain range of said point.
		//These points are then used for main height map. Number of initial points depends on islands-pangea.

	//Generate noise map (perlin?) in green channel. Based on red channel will be determine a range of possible heights.

	//Cliamate map in blue channel. Heavily based on other two channels.

	//Take avarages to determine data.
}
