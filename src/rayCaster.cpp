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
#include "renderEngine.h"

using namespace std;

int main() {
	mapLoader oMapLoader;
	shared_ptr<map> pMap(oMapLoader.loadMapFromFile("level1.map"));

	pMap->PrintMap();
	objectPosition pos = pMap->getDefaultPlayerPos();
	pMap->castRay(pos);
	cout << pMap->getWidth() << "x" << pMap->getHeight() << endl;
	cout << "default player pos: X:" << pMap->getDefaultPlayerPos().x << " Y:" << pMap->getDefaultPlayerPos().y << endl;
	renderEngine oRenderEngine(320,200,60,pMap);
	return 0;
}
