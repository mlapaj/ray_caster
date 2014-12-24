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

}

void KeyboardInput::reactOnKey(SDL_Keycode &code) {
	switch (code)
	{
		case SDLK_q:
		{
			game.endGame();
			break;
		}
		case SDLK_UP:
		{
			game.player->moveForward();
			break;
		}
		case SDLK_DOWN:
		{
			game.player->moveBackward();
			break;
		}
		case SDLK_LEFT:
		{
			game.player->turnLeft();
			break;
		}
		case SDLK_RIGHT:
		{
			game.player->turnRight();
			break;
		}
	}
}

KeyboardInput::~KeyboardInput() {
	// TODO Auto-generated destructor stub
}

} /* namespace RayCaster */
