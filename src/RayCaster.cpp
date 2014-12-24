//============================================================================
// Name        : RayCaster.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <memory>

#include <SDL.h>

#include "RenderEngine.h"

using namespace std;

/*
int main() {
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


				 }

			}
		}


}*/
