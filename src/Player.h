/*
 * Player.h
 *
 *  Created on: 24 gru 2014
 *      Author: lapajmar
 */

#ifndef PLAYER_H_
#define PLAYER_H_


#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"

namespace RayCaster {

class Player {

private:
	int PosOnMapX = 0;
	int PosOnMapY = 0;
	double angle = 0;
	double toDiffX;
	double toDiffY;
	log4cpp::Category& logger = log4cpp::Category::getInstance("Player");
public:
	Player();
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
