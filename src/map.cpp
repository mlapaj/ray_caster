/*
 * Map.cpp
 *
 *  Created on: 15 gru 2014
 *      Author: cod3r
 */

#include "map.h"

map::map(int width,int height,vector<vector<int> > MapData) {
	// TODO Auto-generated constructor stub
	cout << "Map constructor: " << width << "x" << height << endl;
	this->width = width;
	this->height = height;
	this->MapData = MapData;
}

map::~map() {
	cout << "Destructing map." << endl;
}

void map::PrintMap(){
	for (int i=0;i<width;i++)
	{
		for (int j=0;j<height;j++)
		{
			cout << MapData[i][j] << " ";
		}
		cout << std::endl;
	}
}


int map::getHeight(){
	return height * blockSize;
}

int map::getWidth(){
	return width * blockSize;
}
