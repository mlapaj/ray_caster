/*
 * renderEngine.cpp
 *
 *  Created on: 16 gru 2014
 *      Author: lapajmar
 */

#include "renderEngine.h"
#include <cmath>

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
}

void renderEngine::drawFrame(){
	SDL_RenderClear(render);
	objectPosition pos;
	pos.x = 260;
	pos.y = 224;

	for (int i=0;i<180;i++)
	{
		pos.angle = i;
		objectPosition posOut = oMap->castRay(pos);

		SDL_RenderDrawLine(render,pos.x,pos.y,posOut.x,posOut.y);
	}

	for (int i=0;i>-180;i--)
	{
		pos.angle = i;
		objectPosition posOut = oMap->castRay(pos);
		SDL_RenderDrawLine(render,pos.x,pos.y,posOut.x,posOut.y);
	}


	SDL_RenderPresent(render);
}

renderEngine::~renderEngine() {
	//Destroy window
	SDL_DestroyWindow( window );
}

