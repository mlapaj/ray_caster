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
#include <vector>
#include "map.h"

using namespace std;
class mapLoader {
public:
	mapLoader();
	map *loadMapFromFile(string fileName);
	~mapLoader();
};

#endif /* MAPLOADER_H_ */
