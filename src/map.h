/*
 * Map.h
 *
 *  Created on: 15 gru 2014
 *      Author: cod3r
 */

#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <vector>
#include "objectPositon.h"
using namespace std;

struct wallPositionDetails{
	bool isWall;
	int slice;
};


class mapLoader;
class map {
public:
	void PrintMap();
	int getHeight();
	int getWidth();
	objectPosition getDefaultPlayerPos();
	bool isWallOnPosition(long x,long y,wallPositionDetails *details);
	int getMapBlockSize();
	virtual ~map();
	friend class mapLoader;
private:
	int heightInBlocks;
	int widthInBlocks;

	int height;
	int width;

	const int blockSize = 64;
	struct objectPosition defaultPlayerPos;
	vector<vector<int> > MapData;
	map(int height,int width,objectPosition pos,vector<vector<int> > MapData);

};

#endif /* MAP_H_ */
