/*
 * Game.h
 *
 *  Created on: 23 gru 2014
 *      Author: lapajmar
 */

#ifndef GAME_H_
#define GAME_H_
#include <memory>

#include "Map.h"
#include "RenderEngine.h"
#include "KeyboardInput.h"
#include "Player.h"
#include "Textures.h"
#include "MapGenerator.h"

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"



namespace RayCaster {

class Game {
public:
	Game();
	virtual ~Game();
	void mainLoop();
	void endGame();
	shared_ptr<RayCaster::Player> player;
private:
	bool hasEnded = false;
	const int screenWidth = 800;
	const int screenHeight = 600;
	const int screenFov = 60;
	log4cpp::Category& logger = log4cpp::Category::getInstance("Game");
	shared_ptr<RayCaster::Map> currentMap;
	shared_ptr<RayCaster::RenderEngine> renderEngine;
	shared_ptr<RayCaster::KeyboardInput> keyboardInput;


};

} /* namespace RayCaster */

#endif /* GAME_H_ */
