/*
 * renderEngine.h
 *
 *  Created on: 16 gru 2014
 *      Author: lapajmar
 */

#ifndef RENDERENGINE_H_
#define RENDERENGINE_H_
#include <memory>
#include "map.h"
#include <SDL.h>

class renderEngine {
public:
	double debugAngle = 0;
	int debugRow = 1;
	long debugPlayerPositionX = 256;
	long debugPlayerPositionY = 256;

	renderEngine(int resX,int resY,int fov,shared_ptr<map> rMap);
	void drawFrame();
	void debugDrawFrame();
	virtual ~renderEngine();
private:
	int mapBlockSize;
	int resX;
	int resY;
	SDL_Window* window = NULL;
	SDL_Renderer *render;
	int dToProjectionPlane;

	double fov; // in radians
	double halfFov;
	double angleBetweenRays; // in radians
	shared_ptr<map> &oMap;
	objectPosition castRayHorizontally(objectPosition pos);
	objectPosition castRayVeritically(objectPosition pos);
};

#endif /* RENDERENGINE_H_ */
