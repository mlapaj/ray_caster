/*
 * renderEngine.cpp
 *
 *  Created on: 16 gru 2014
 *      Author: lapajmar
 */

#include "renderEngine.h"
#include <cmath>
#define deg2rad(x) ((x) * M_PI / 180.0)

renderEngine::renderEngine(int resX, int resY, int fov, shared_ptr<map> rMap):oMap(rMap) {

	 //Create window
	 window = SDL_CreateWindow( "SDL Tutorial", 100, 100, resX, resY, SDL_WINDOW_SHOWN );
	 if( window == NULL )
	 {
		 printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
	 }
	 else
	 {
		 render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		  if (render == nullptr){
			 	SDL_DestroyWindow(window);
			 	std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			 	SDL_Quit();
			 	return;
			 }

	 }


	this->resX = resX;
	this->resY = resY;
	this->fov = fov * M_PI / 180.0 ;
	this->halfFov = this->fov / 2;
	this->angleBetweenRays =  (this->resX / fov) * M_PI / 180.0;
	dToProjectionPlane = (resX/2)  / tan(this->fov/2);
	cout << "screen resolution: " << resX << "x" << resY << endl;
	cout << "distance to proj plane: " << dToProjectionPlane << endl;
	cout << "angle Between rays: " << this->angleBetweenRays << endl;
	// this should be changed when map block size will change from level to level
	mapBlockSize = rMap->getMapBlockSize();
}

void renderEngine::drawFrame(){
	SDL_RenderClear(render);
	objectPosition pos;
	pos.x = 230;
	pos.y = 224;



	for (double i=debugAngle;i<debugAngle+halfFov;i+=0.1)
	{
		pos.angle = i;
		objectPosition posOut = castRayHorizontally(pos);

		SDL_RenderDrawLine(render,pos.x,pos.y,posOut.x,posOut.y);
	}


	for (double i=debugAngle;i>debugAngle-halfFov;i-=0.1)
	{
		pos.angle = i;
		objectPosition posOut = castRayHorizontally(pos);
		SDL_RenderDrawLine(render,pos.x,pos.y,posOut.x,posOut.y);
	}

	SDL_RenderPresent(render);
}

renderEngine::~renderEngine() {
	//Destroy window
	SDL_DestroyWindow( window );
}


// its ok
objectPosition renderEngine::castRayHorizontally(objectPosition pos)
{
	// we should normalize angle here

	double angle =  pos.angle;
	if (angle=> 2*M_M_PI) || (angle<= -2*M_PI) angle = 0;
	long deltaYa;
	long deltaXa;
	// first coordinates
	if ((angle >= -M_PI/2) && (angle <= M_PI/2))
	{
		deltaYa = - (pos.y - (pos.y / mapBlockSize) * mapBlockSize);
        deltaXa = - (deltaYa * tan(angle));
		//cout << "1 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;
	}
	else
	{
		deltaYa = -(pos.y-(pos.y / mapBlockSize + 1) * mapBlockSize);
		deltaXa = -(deltaYa * tan(angle));
		//cout << "2 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;
	}

	// adding constant value - can be precalculated earlier
	pos.x = pos.x + deltaXa;
	pos.y = pos.y + deltaYa;

	if ((angle >= -M_PI/2) && (angle <= M_PI/2))
	{
		deltaYa = -(mapBlockSize);
		deltaXa = -(deltaYa * tan(angle));

	}
	else
	{
		deltaYa = mapBlockSize;
		deltaXa = -(deltaYa * tan(angle));
		//cout << "4 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;
	}

	for (int i=0;i<debugRow;i++)
	{
	pos.x = pos.x + deltaXa;
	pos.y = pos.y + deltaYa;
	}

	return pos;
}


// its not ok
objectPosition renderEngine::castRayVeritically(objectPosition pos)
{
	// we should normalize angle
	double angle =  pos.angle;
	long deltaYa;
	long deltaXa;
	// first coordinates
	if ((angle > 0) && (angle < M_PI))
	{
		deltaXa = 0;
		deltaYa = 0;
		deltaXa = - (pos.x - int(pos.x / mapBlockSize) * mapBlockSize);
        deltaYa = (deltaXa / tan(angle));

		cout << "ver 1 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;

	}
	else
	{
		deltaXa = 0;
		deltaYa = 0;
		deltaXa = -(pos.x - int(pos.x / mapBlockSize  + 1) * mapBlockSize);
		deltaYa = (deltaXa / tan(angle));
		cout << "ver 2 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;
		// to fill
	}


	pos.x = pos.x + deltaXa;
	pos.y = pos.y + deltaYa;


	return pos;
}
