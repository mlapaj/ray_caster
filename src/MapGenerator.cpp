/*
 * MapGenerator.cpp
 *
 *  Created on: 14 sty 2015
 *      Author: lapajmar
 */

#include "MapGenerator.h"
#include "Map.h"


namespace RayCaster {
Map *MapGenerator::GenerateMap(int size){
	Map *map = new Map();
	map->widthInBlocks = size;
	map->heightInBlocks = size;
	map->width = map->widthInBlocks * map->blockSize;
	map->height = map->heightInBlocks * map->blockSize;

	ObjectPosition playerPos;
	playerPos.x = 128;
	playerPos.y = 128;
	playerPos.angle = 0;
	map->defaultPlayerPos = playerPos;






	vector<vector<int> > mapData(map->height, std::vector<int>(map->width));
	for (int i=0;i<map->width;i++)
	{
		mapData[0][i] = 1;
		mapData[map->height-1][i] = 1;
	}

	for (int i=0;i<map->height;i++)
	{
		mapData[i][0] = 1;
		mapData[i][map->width-1] = 1;
	}

	map->MapData = mapData;

	return map;

}


} /* namespace RayCaster */
