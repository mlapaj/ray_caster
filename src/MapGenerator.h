/*
 * MapGenerator.h
 *
 *  Created on: 14 sty 2015
 *      Author: lapajmar
 */

#ifndef MAPGENERATOR_H_
#define MAPGENERATOR_H_


#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"

#include "Map.h"

namespace RayCaster {

class MapGenerator {
private:
	MapGenerator(int size){}
public:
	static Map *GenerateMap(int size);
	virtual ~MapGenerator();
};

} /* namespace RayCaster */

#endif /* MAPGENERATOR_H_ */
