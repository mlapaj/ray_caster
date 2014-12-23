/*
 * renderEngine.h
 *
 *  Created on: 16 gru 2014
 *      Author: lapajmar
 */

#ifndef RENDERENGINE_H_
#define RENDERENGINE_H_
#include <memory>
#include <SDL.h>
#include "Map.h"

class RenderEngine {
public:
	bool debugDistor = false;
	double debugAngle = 0;
	int debugRow = 1;
	long debugPlayerPositionX = 256;
	long debugPlayerPositionY = 256;
	void debugForward();
	void debugBackward();

	double toDiffX = 0;
	double toDiffY = 0;
	double diffX = 0;
	double diffY = 0;

	SDL_Surface *temp;
	SDL_Texture *texture;



	RenderEngine(int resX,int resY,int fov,shared_ptr<RayCaster::Map> rMap);
	void drawFrame();
	void drawSlice(int which,int height,int sliceNo);
	void debugDrawFrame();
	void debugPlane();
	virtual ~RenderEngine();
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
	shared_ptr<RayCaster::Map> &oMap;
	ObjectPosition castRayHorizontally(ObjectPosition pos);
	ObjectPosition castRayVeritically(ObjectPosition pos);
};

#endif /* RENDERENGINE_H_ */
