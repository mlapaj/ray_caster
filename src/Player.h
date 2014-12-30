/*
 * Player.h
 *
 *  Created on: 24 gru 2014
 *      Author: lapajmar
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>


#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"

#include "Map.h"
#include "ObjectPositon.h"

using namespace std;

namespace RayCaster {

class Player {

private:
	int PosOnMapX = 0;
	int PosOnMapY = 0;
	double angle = 0;
	int toDiffX;
	int toDiffY;
	log4cpp::Category& logger = log4cpp::Category::getInstance("Player");
    shared_ptr<Map> map;
public:
	Player(shared_ptr<Map> map);
	void setPlayerPos(int PosX,int PosY,double angle);
	int getPlayerPosX();
	int getPlayerPosY();
	double getPlayerAngle();
	void moveForward();
	void moveBackward();
	void turnLeft();
	void turnRight();

	virtual ~Player();
};

} /* namespace RayCaster */

#endif /* PLAYER_H_ */
