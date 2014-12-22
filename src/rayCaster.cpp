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
				 switch (e.key.keysym.sym)
				 {
					 case SDLK_q:
					 {
						 quit = true;
						 break;
					 }

					 case SDLK_k:
					 {
						 oRenderEngine.debugRow+=1;
						 cout << "debugRow" << oRenderEngine.debugRow << endl;
						 break;
					 }
					 case SDLK_l:
					 {
						 oRenderEngine.debugRow-=1;
						 cout << "debugRow" << oRenderEngine.debugRow << endl;
						 break;
					 }
/*
					 case SDLK_UP:
					 {
						 oRenderEngine.debugPlayerPositionY--;
						 cout << "debugRow" << oRenderEngine.debugRow << endl;
						 break;
					 }
					 case SDLK_DOWN:
					 {
						 oRenderEngine.debugPlayerPositionY++;
						 cout << "debugRow" << oRenderEngine.debugRow << endl;
						 break;
					 }
*/
					 case SDLK_UP:
					 {
						 oRenderEngine.debugForward();
						 break;
					 }
					 case SDLK_DOWN:
					 {
						 oRenderEngine.debugBackward();
						 break;
					 }

					 case SDLK_RIGHT:
					 {
						 oRenderEngine.debugAngle += 0.1;
						 if (oRenderEngine.debugAngle >= 2 * M_PI){
							 oRenderEngine.debugAngle = 0;
						 }
						 cout << oRenderEngine.debugAngle << endl;
						 break;
					 }
					 case SDLK_LEFT:
					 {
						 oRenderEngine.debugAngle -= 0.1;
						 if (oRenderEngine.debugAngle <= -2 * M_PI){
							 oRenderEngine.debugAngle = 0;
						 }
						 cout << oRenderEngine.debugAngle << endl;
						 break;
					 }

/*

					 case SDLK_LEFT:
					 {
						 oRenderEngine.debugPlayerPositionX--;
						 cout << "debugRow" << oRenderEngine.debugRow << endl;
						 break;
					 }
					 case SDLK_RIGHT:
					 {
						 oRenderEngine.debugPlayerPositionX++;
						 cout << "debugRow" << oRenderEngine.debugRow << endl;
						 break;
					 }
*/

				 }

			}
		}

	//Quit SDL subsystems
	SDL_Quit();
	return 0;
}
