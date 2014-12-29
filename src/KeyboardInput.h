/*
 * KeyboardInput.h
 *
 *  Created on: 24 gru 2014
 *      Author: lapajmar
 */
#include <SDL.h>

#include "Game.h"
#include "Player.h"

#ifndef KEYBOARDINPUT_H_
#define KEYBOARDINPUT_H_

namespace RayCaster {
class Game;
class Player;

class KeyboardInput {
public:
	KeyboardInput(Game &game);
	virtual ~KeyboardInput();
	void reactOnKeyDown(SDL_Keycode &code);
	void reactOnKeyUp(SDL_Keycode &code);
	void action();
private:
	Game &game;
	bool moveForward;
	bool moveBackward;
	bool moveLeft;
	bool moveRight;
};

} /* namespace RayCaster */

#endif /* KEYBOARDINPUT_H_ */
