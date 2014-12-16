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
#include <SDL.h>

using namespace std;

int main() {
	const int screenWidth = 640;
	const int screenHeight = 480;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}

	mapLoader oMapLoader;
	shared_ptr<map> pMap(oMapLoader.loadMapFromFile("level1.map"));

	pMap->PrintMap();
	objectPosition pos = pMap->getDefaultPlayerPos();
	pMap->castRay(pos);
	cout << pMap->getWidth() << "x" << pMap->getHeight() << endl;
	cout << "default player pos: X:" << pMap->getDefaultPlayerPos().x << " Y:" << pMap->getDefaultPlayerPos().y << endl;


	renderEngine oRenderEngine(screenWidth,screenHeight,60,pMap);

	 SDL_Event e;
	 bool quit = false;

	 while ((!quit) && SDL_WaitEvent(&e))
		{
		 oRenderEngine.drawFrame();
		 if (e.type == SDL_QUIT){
			 quit = true;
		 }
		 if (e.type == SDL_KEYDOWN)
		 {
			 quit = true;
		 }

		}

	//Quit SDL subsystems
	SDL_Quit();
	return 0;
}
