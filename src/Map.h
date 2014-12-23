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
#include <string>

#include "ObjectPositon.h"
using namespace std;

struct wallPositionDetails{
	bool isWall;
	int slice;
};

class MapLoader;
namespace RayCaster
{
	class Map {
	public:
		Map(string fileName);
		void PrintMap();
		int getHeight();
		int getWidth();
		ObjectPosition getDefaultPlayerPos();
		bool isWallOnPosition(long x,long y,wallPositionDetails *details);
		int getMapBlockSize();
		virtual ~Map();
		friend class MapLoader;
		// temporary
		Map(int height,int width,ObjectPosition pos,vector<vector<int> > MapData);
	private:
		int heightInBlocks;
		int widthInBlocks;

		int height;
		int width;

		const int blockSize = 64;
		struct ObjectPosition defaultPlayerPos;
		vector<vector<int> > MapData;
	};
}
#endif /* MAP_H_ */
