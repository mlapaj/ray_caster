/*
 * Game.cpp
 *
 *  Created on: 23 gru 2014
 *      Author: lapajmar
 */

#include "Game.h"

namespace RayCaster {

Game::Game() {
	currentMap.reset(new Map("level1.map"));
}

Game::~Game() {
}

} /* namespace RayCaster */
