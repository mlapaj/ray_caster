/*
 * Game.h
 *
 *  Created on: 23 gru 2014
 *      Author: lapajmar
 */

#ifndef GAME_H_
#define GAME_H_
#include <memory>
#include <log4cxx/logger.h>

#include "Map.h"

using namespace log4cxx;

namespace RayCaster {

class Game {
public:
	Game();
	virtual ~Game();
private:
	shared_ptr<RayCaster::Map> currentMap;
};

} /* namespace RayCaster */

#endif /* GAME_H_ */
