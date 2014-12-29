/*
 * Game.cpp
 *
 *  Created on: 23 gru 2014
 *      Author: lapajmar
 */

#include "Game.h"

namespace RayCaster {

Game::Game() {
	logger << log4cpp::Priority::DEBUG << "Class constructor";
	player.reset(new Player());
	player->setPlayerPos(255,255,0);
    currentMap.reset(new Map("level1.map"));
    renderEngine.reset(new RenderEngine(screenWidth,screenHeight,screenFov,currentMap,player));
    keyboardInput.reset(new KeyboardInput(*this));
}

void Game::mainLoop() {
	 SDL_Event e;

	 while (!hasEnded)
	 {
		 while  (SDL_PollEvent(&e))
		 {
			 if (e.type == SDL_QUIT){
				 hasEnded = true;
			 }
			 if (e.type == SDL_KEYDOWN)
			 {
				 keyboardInput->reactOnKeyDown(e.key.keysym.sym);
			 }
			 if (e.type == SDL_KEYUP)
			 {
				 keyboardInput->reactOnKeyUp(e.key.keysym.sym);
			 }

		 }
		 renderEngine->drawFrame();
		 keyboardInput->action();
		 SDL_Delay(20);

	 }

}

void Game::endGame()
{
	hasEnded = true;
}


Game::~Game() {
	logger << log4cpp::Priority::DEBUG << "Class destructor";
}

} /* namespace RayCaster */
