/*
 * Map.cpp
 *
 *  Created on: 15 gru 2014
 *      Author: cod3r
 */

#include "map.h"
#include <cmath>
#define deg2rad(x) ((x) * M_PI / 180.0)

map::map(int width,int height,objectPosition pos,vector<vector<int> > MapData) {
	// TODO Auto-generated constructor stub
	cout << "Map constructor: " << width << "x" << height << endl;
	defaultPlayerPos = pos;
	defaultPlayerPos.x = (defaultPlayerPos.x * blockSize) + blockSize/2;
	defaultPlayerPos.y = (defaultPlayerPos.y * blockSize) + blockSize/2;

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


objectPosition map::getDefaultPlayerPos()
{
	return defaultPlayerPos;
}


void map::castRay(objectPosition pos)
{
	int angleDeg =  89;

	if ((angleDeg> -90) && (angleDeg < 90))
	{
		int deltaYa = pos.y - int(pos.y - pos.y % blockSize);

        int deltaXa = deltaYa * tan(deg2rad(angleDeg));
		cout << "deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;

	}
	else
	{

		int deltaYa = -(pos.y - int(pos.y - pos.y % blockSize));
		int deltaXa = (deltaYa * tan(deg2rad(angleDeg)));
		cout << "deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;
	}
}

