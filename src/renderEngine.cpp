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
	pos.x = 260;
	pos.y = 224;

	for (int i=0;i<90;i++)
	{
		pos.angle = i;
		objectPosition posOut = castRayVeritically(pos);

		SDL_RenderDrawLine(render,pos.x,pos.y,posOut.x,posOut.y);
	}
/*
	for (int i=0;i>-180;i--)
	{
		pos.angle = i;
		objectPosition posOut = castRayHorizontally(pos);
		SDL_RenderDrawLine(render,pos.x,pos.y,posOut.x,posOut.y);
	}
*/

	SDL_RenderPresent(render);
}

renderEngine::~renderEngine() {
	//Destroy window
	SDL_DestroyWindow( window );
}


// its ok
objectPosition renderEngine::castRayHorizontally(objectPosition pos)
{
	int angleDeg =  pos.angle;
	long deltaYa;
	long deltaXa;
	if ((angleDeg >= -90) && (angleDeg <= 90))
	{
		deltaYa = - (pos.y - int(pos.y - pos.y % mapBlockSize));
        deltaXa = - (deltaYa * tan(deg2rad(angleDeg)));
		cout << "1 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;

	}
	else
	{

		deltaYa = (pos.y - int(pos.y - pos.y % mapBlockSize));
		deltaXa = -(deltaYa * tan(deg2rad(angleDeg)));
		cout << "2 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;
	}


	pos.x = pos.x + deltaXa;
	pos.y = pos.y + deltaYa;

    // first coordinates
	if ((angleDeg >= -90) && (angleDeg <= 90))
	{
		deltaXa = -(mapBlockSize / tan(deg2rad(angleDeg)));
		deltaYa = -(mapBlockSize);
	}
	else
	{
		deltaXa = mapBlockSize / tan(deg2rad(angleDeg));
		deltaYa = mapBlockSize;
	}

	for (int i=0;i<3;i++)
	{
	pos.x = pos.x + deltaXa;
	pos.y = pos.y + deltaYa;
	}

	return pos;
}


// its not ok
objectPosition renderEngine::castRayVeritically(objectPosition pos)
{
	int angleDeg =  pos.angle;
	long deltaYa;
	long deltaXa;
	// first coordinates
	if ((angleDeg >= 0) && (angleDeg <= 180))
	{
		deltaXa = - (pos.x - int(pos.x - pos.x % mapBlockSize));
		cout << "!!" << int(pos.x) <<endl;
        deltaYa = - (deltaXa / tan(deg2rad(angleDeg)));
		cout << "ver 1 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;

	}
	else
	{
		deltaXa = - (pos.x - int(pos.x - pos.x % mapBlockSize));
		deltaYa = (deltaXa / tan(deg2rad(angleDeg)));
		cout << "ver 2 deltaXa: " << deltaXa << " deltaYa: " << deltaYa << endl;
		// to fill
	}


	pos.x = pos.x + deltaXa;
	pos.y = pos.y + deltaYa;


	return pos;
}
