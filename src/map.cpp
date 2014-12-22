/*
 * Map.cpp
 *
 *  Created on: 15 gru 2014
 *      Author: cod3r
 */

#include "map.h"
#include <cmath>


map::map(int width,int height,objectPosition pos,vector<vector<int> > MapData) {
	// TODO Auto-generated constructor stub
	cout << "Map constructor: " << width << "x" << height << endl;
	defaultPlayerPos = pos;
	defaultPlayerPos.x = (defaultPlayerPos.x * blockSize) + blockSize/2;
	defaultPlayerPos.y = (defaultPlayerPos.y * blockSize) + blockSize/2;

	this->widthInBlocks = width;
	this->heightInBlocks = height;
	this->width = width * blockSize;
	this->height = height * blockSize;
	this->MapData = MapData;

}

map::~map() {
	cout << "Destructing map." << endl;
}

void map::PrintMap(){
	for (int i=0;i<heightInBlocks;i++)
	{
		for (int j=0;j<widthInBlocks;j++)
		{
			cout << MapData[i][j] << " ";
		}
		cout << std::endl;
	}
}


int map::getHeight(){
	return heightInBlocks * blockSize;
}

int map::getWidth(){
	return heightInBlocks * blockSize;
}


objectPosition map::getDefaultPlayerPos()
{
	return defaultPlayerPos;
}


int map::getMapBlockSize()
{
	return blockSize;
}


bool map::isWallOnPosition(long x,long y)
{
	bool retVal = false;
	long cordX = x/blockSize;
	long cordY = y/blockSize;
	try{
	if ((cordX<0) || (cordX>=widthInBlocks)){ retVal = true;}
	else if ((cordY<0) || (cordY>=heightInBlocks)){ retVal = true;}
	else if (MapData[cordX][cordY] != 0){
		retVal = true;
	}
	//if (retVal == true)
	{
		//cout << "x: " << x << "y: " << y << "cordX: " <<  cordX << " cordY: " << cordY << " Data: " << ":"  << retVal << endl;
	}
	}
	catch (...)
	{
		cout << "error";
	}

	return retVal;
}
