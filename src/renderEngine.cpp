/*
 * renderEngine.cpp
 *
 *  Created on: 16 gru 2014
 *      Author: lapajmar
 */

#include "renderEngine.h"
#include <cmath>

renderEngine::renderEngine(int resX, int resY, int fov, shared_ptr<map> rMap):oMap(rMap) {
	this->resX = resX;
	this->resY = resY;
	this->fov = fov * M_PI / 180.0 ;
	this->angleBetweenRays =  (this->resX / fov) * M_PI / 180.0;
	dToProjectionPlane = (resX/2)  / tan(this->fov/2);
	cout << "screen resolution: " << resX << "x" << resY << endl;
	cout << "distance to proj plane: " << dToProjectionPlane << endl;
	cout << "angle Between rays: " << this->angleBetweenRays << endl;
}

renderEngine::~renderEngine() {
	// TODO Auto-generated destructor stub
}

