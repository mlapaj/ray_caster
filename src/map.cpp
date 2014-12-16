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


objectPosition map::castRay(objectPosition pos)
{
	int angleDeg =  pos.angle;
	long deltaYa;
	long deltaXa;
	if ((angleDeg >= -90) && (angleDeg <= 90))
	{
		deltaYa = - (pos.y - int(pos.y - pos.y % blockSize));
        deltaXa = - (deltaYa * tan(deg2rad(angleDeg)));
		cout << "1 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;

	}
	else
	{

		deltaYa = (pos.y - int(pos.y - pos.y % blockSize));
		deltaXa = -(deltaYa * tan(deg2rad(angleDeg)));
		cout << "2 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;
	}
	pos.x = pos.x + deltaXa;
	pos.y = pos.y + deltaYa;
	return pos;
}

