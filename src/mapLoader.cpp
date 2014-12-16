/*
 * MapLoader.cpp
 *
 *  Created on: 15 gru 2014
 *      Author: cod3r
 */

#include "mapLoader.h"
#include "objectPositon.h"


mapLoader::mapLoader() {
	cout << "creating map loader" << endl;
}

mapLoader::~mapLoader() {
	cout << "destructing map loader" << endl;
}

map *mapLoader::loadMapFromFile(string fileName){
	int height;
	int width;
	int player_x, player_y,player_angle;
	cout << "Loading map. Filename: " << fileName << endl;
	ifstream mapa;
	mapa.open(fileName.c_str());
	if (mapa.is_open()){
		mapa >> height;
		mapa >> width;
		objectPosition playerPos;
		mapa >> player_x;
		mapa >> player_y;
		mapa >> player_angle;
		playerPos.x = player_x;
		playerPos.y = player_y;
		playerPos.angle = player_angle;

		vector<vector<int> > mapData(height, std::vector<int>(width));
		for (int i=0;i<width;i++)
		{
			for (int j=0;j<height;j++)
			{
				mapa >> mapData[i][j];
			}
		}
		mapa.close();
		map *oMap = new map(width,height,playerPos,mapData);
		return oMap;
	}
	else
	{
		cout << "file not found" << endl;
	}
	return NULL;
}
