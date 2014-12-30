/*
 * KeyboardInput.cpp
 *
 *  Created on: 24 gru 2014
 *      Author: lapajmar
 */

#include "KeyboardInput.h"


namespace RayCaster {

KeyboardInput::KeyboardInput(Game &game):game(game) {
	// TODO Auto-generated constructor stub
	moveBackward = false;
	moveForward = false;
	moveLeft = false;
	moveRight = false;
}

void KeyboardInput::reactOnKeyDown(SDL_Keycode &code) {
	switch (code)
	{
		case SDLK_q:
		{
			game.endGame();
			break;
		}
		case SDLK_UP:
		{
			moveForward = true;
			break;
		}
		case SDLK_DOWN:
		{
			moveBackward = true;
			break;
		}
		case SDLK_LEFT:
		{
			moveLeft = true;
			break;
		}
		case SDLK_RIGHT:
		{
			moveRight = true;
			break;
		}
	}
}


void KeyboardInput::reactOnKeyUp(SDL_Keycode &code) {
	switch (code)
	{
		case SDLK_q:
		{
			game.endGame();
			break;
		}
		case SDLK_UP:
		{
			moveForward = false;
			break;
		}
		case SDLK_DOWN:
		{
			moveBackward = false;
			break;
		}
		case SDLK_LEFT:
		{
			moveLeft = false;
			break;
		}
		case SDLK_RIGHT:
		{
			moveRight = false;
			break;
		}
	}
}



void KeyboardInput::action(){
	if (moveForward) game.player->moveForward();
	if (moveBackward) game.player->moveBackward();
	if (moveRight) game.player->turnRight();
	if (moveLeft) game.player->turnLeft();
}


KeyboardInput::~KeyboardInput() {
	// TODO Auto-generated destructor stub
}

} /* namespace RayCaster */
