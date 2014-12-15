/*
 * MapLoader.h
 *
 *  Created on: 15 gru 2014
 *      Author: cod3r
 */

#ifndef MAPLOADER_H_
#define MAPLOADER_H_
#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include <vector>

using namespace std;
class MapLoader {
public:
	MapLoader();
	Map *loadMapFromFile(string fileName);
	~MapLoader();
};

#endif /* MAPLOADER_H_ */
