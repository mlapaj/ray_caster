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
#include <memory>

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"


#include "Object.h"
#include "ObjectPositon.h"
#include "CastInfo.h"
using namespace std;

struct wallPositionDetails{
	bool isWall;
	int slice;
};


class MapGenerator;
namespace RayCaster
{
	class Map {
	public:
		Map(){};
		Map(string fileName);
		void PrintMap();
		int getHeight();
		int getWidth();
		ObjectPosition getDefaultPlayerPos();
		bool isWallOnPosition(long x,long y);
		bool isWallOnPosition(long x,long dx,long y,long dy,CastInfo &details);
		int getMapBlockSize();
		virtual ~Map();
		friend class MapGenerator;
		// temporary
	private:
		log4cpp::Category& logger = log4cpp::Category::getInstance("Map");
		int heightInBlocks;
		int widthInBlocks;

		int height;
		int width;

		const int blockSize = 64;
		struct ObjectPosition defaultPlayerPos;
		vector<vector<int> > MapData;
		map<int,shared_ptr<Object>> itemData;
	};
}
#endif /* MAP_H_ */
