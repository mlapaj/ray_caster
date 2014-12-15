/*
 * Map.cpp
 *
 *  Created on: 15 gru 2014
 *      Author: cod3r
 */

#include "Map.h"

Map::Map(int width,int height,vector<vector<int> > MapData) {
	// TODO Auto-generated constructor stub
	cout << "Map constructor: " << width << "x" << height << endl;
	this->width = width;
	this->height = height;
	this->MapData = MapData;
}

Map::~Map() {
	cout << "Destructing map." << endl;
}

void Map::PrintMap(){
	for (int i=0;i<width;i++)
	{
		for (int j=0;j<height;j++)
		{
			cout << MapData[i][j] << " ";
		}
		cout << std::endl;
	}
}
