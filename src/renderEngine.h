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
	renderEngine(int resX,int resY,int fov,shared_ptr<map> rMap);
	void drawFrame();
	virtual ~renderEngine();
private:
	int resX;
	int resY;
	SDL_Window* window = NULL;
	SDL_Renderer *render;
	int dToProjectionPlane;

	double fov; // in radians
	double angleBetweenRays; // in radians
	shared_ptr<map> &oMap;
};

#endif /* RENDERENGINE_H_ */