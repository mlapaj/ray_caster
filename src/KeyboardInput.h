/*
 * KeyboardInput.h
 *
 *  Created on: 24 gru 2014
 *      Author: lapajmar
 */
#include <SDL.h>

#include "Game.h"

#ifndef KEYBOARDINPUT_H_
#define KEYBOARDINPUT_H_

namespace RayCaster {
class Game;
class KeyboardInput {
public:
	KeyboardInput(Game &game);
	virtual ~KeyboardInput();
	void reactOnKey(SDL_Keycode &code);
private:
	Game &game;
};

} /* namespace RayCaster */

#endif /* KEYBOARDINPUT_H_ */
