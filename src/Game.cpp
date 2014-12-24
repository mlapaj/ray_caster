/*
 * Game.cpp
 *
 *  Created on: 23 gru 2014
 *      Author: lapajmar
 */

#include "Game.h"

namespace RayCaster {

Game::Game() {
	logger.debug("Class constructor");
    currentMap.reset(new Map("level1.map"));
    renderEngine.reset(new RenderEngine(screenWidth,screenHeight,screenFov,currentMap));
    keyboardInput.reset(new KeyboardInput(*this));
}

void Game::mainLoop() {
	 SDL_Event e;


	 while ((!hasEnded) && SDL_WaitEvent(&e))
	 {
		 renderEngine->drawFrame();
		 if (e.type == SDL_QUIT){
			 hasEnded = true;
		 }
		 if (e.type == SDL_KEYDOWN)
		 {
			 keyboardInput->reactOnKey(e.key.keysym.sym);
		 }
	 }

}

void Game::endGame()
{
	hasEnded = true;
}


Game::~Game() {
	logger.debug("Class destructor");
}

} /* namespace RayCaster */
