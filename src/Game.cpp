/*
 * Game.cpp
 *
 *  Created on: 23 gru 2014
 *      Author: lapajmar
 */

#include "Game.h"

namespace RayCaster {

Game::Game():logger(log4cxx::Logger::getLogger("Game")) {
	LOG4CXX_TRACE(logger, "Class created");
	currentMap.reset(new Map("level1.map"));
}

Game::~Game() {
	LOG4CXX_TRACE(logger, "Class destroyed");
}

} /* namespace RayCaster */
