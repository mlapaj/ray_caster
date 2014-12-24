/*
 * Map.cpp
 *
 *  Created on: 15 gru 2014
 *      Author: cod3r
 */

#include "Map.h"

#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

RayCaster::Map::Map(string fileName){
	logger << log4cpp::Priority::DEBUG << "Class constructor";

	int height;
	int width;
	int player_x, player_y,player_angle;

	logger << log4cpp::Priority::DEBUG << "Loading map. Filename: " << fileName;


	ifstream mapa;
	mapa.open(fileName.c_str());
	if (mapa.is_open()){
		mapa >> height;
		mapa >> width;
		ObjectPosition playerPos;
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


		defaultPlayerPos = playerPos;
		defaultPlayerPos.x = (defaultPlayerPos.x * blockSize) + blockSize/2;
		defaultPlayerPos.y = (defaultPlayerPos.y * blockSize) + blockSize/2;

		this->width = width * blockSize;
		this->height = height * blockSize;
		this->MapData = mapData;
		this->widthInBlocks = width;
		this->heightInBlocks = height;

	}
	else
	{
		cout << "file not found" << endl;
	}
	return;
}



RayCaster::Map::~Map() {
	logger << log4cpp::Priority::DEBUG << "Class destructor";
}

void RayCaster::Map::PrintMap(){
	for (int i=0;i<heightInBlocks;i++)
	{
		for (int j=0;j<widthInBlocks;j++)
		{
			cout << MapData[i][j] << " ";
		}
		cout << std::endl;
	}
}


int RayCaster::Map::getHeight(){
	return heightInBlocks * blockSize;
}

int RayCaster::Map::getWidth(){
	return heightInBlocks * blockSize;
}


ObjectPosition RayCaster::Map::getDefaultPlayerPos()
{
	return defaultPlayerPos;
}


int RayCaster::Map::getMapBlockSize()
{
	return blockSize;
}


bool RayCaster::Map::isWallOnPosition(long x,long y,wallPositionDetails *details)
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
	if (retVal == true)
	{
		//cout << "x: " << x << "y: " << y << "cordX: " <<  cordX << " cordY: " << cordY << " Data: " << ":"  << retVal << endl;
	}
	}
	catch (...)
	{
		cout << "error";
	}
	details->isWall = retVal;
	return retVal;
}
