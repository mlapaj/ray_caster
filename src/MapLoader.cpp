/*
 * MapLoader.cpp
 *
 *  Created on: 15 gru 2014
 *      Author: cod3r
 */

#include "MapLoader.h"


MapLoader::MapLoader() {
	cout << "creating map loader" << endl;
}

MapLoader::~MapLoader() {
	cout << "destructing map loader" << endl;
}

Map *MapLoader::loadMapFromFile(string fileName){
	int height;
	int width;

	cout << "Loading map. Filename: " << fileName << endl;
	ifstream mapa;
	mapa.open(fileName.c_str());
	if (mapa.is_open()){
		mapa >> height;
		mapa >> width;
		vector<vector<int> > map(height, std::vector<int>(width));
		for (int i=0;i<width;i++)
		{
			for (int j=0;j<height;j++)
			{
				mapa >> map[i][j];
			}
		}
		mapa.close();
		Map *oMap = new Map(width,height,map);
		return oMap;
	}
	else
	{
		cout << "file not found" << endl;
	}
	return NULL;
}
