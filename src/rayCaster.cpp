//============================================================================
// Name        : RayCaster.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <memory>

#include "mapLoader.h"
using namespace std;

int main() {
	mapLoader oMapLoader;
	shared_ptr<map> pMap(oMapLoader.loadMapFromFile("level1.map"));

	pMap->PrintMap();
	cout << pMap->getWidth() << "x" << pMap->getHeight() << endl;
	return 0;
}
