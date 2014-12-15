//============================================================================
// Name        : RayCaster.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "MapLoader.h"
#include <iostream>
#include <memory>
using namespace std;

int main() {
	MapLoader oMapLoader;
	shared_ptr<Map> pMap(oMapLoader.loadMapFromFile("level1.map"));

	pMap->PrintMap();
	return 0;
}
