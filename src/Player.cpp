/*
 * Player.cpp
 *
 *  Created on: 24 gru 2014
 *      Author: lapajmar
 */

#include "Player.h"
#include <math.h>
namespace RayCaster {

Player::Player() {
	logger << log4cpp::Priority::DEBUG << "Class create";
}

Player::~Player() {
	logger << log4cpp::Priority::DEBUG << "Class destroy";
}

void Player::setPlayerPos(int PosX,int PosY,double angle) {
	this->PosOnMapX = PosX;
	this->PosOnMapY = PosY;
	this->angle = angle;

	toDiffX= 6*(sin(angle));
	toDiffY= 6*(-cos(angle));
}

int Player::getPlayerPosX() {
	return PosOnMapX;
}

int Player::getPlayerPosY() {
	return PosOnMapY;
}


double Player::getPlayerAngle() {
	return angle;
}


void Player::moveForward(){
	PosOnMapX += toDiffX;
	PosOnMapY += toDiffY;

}

void Player::moveBackward(){
	PosOnMapX -= toDiffX;
	PosOnMapY -= toDiffY;
}

void Player::turnLeft(){
	angle -=0.1;
	if (angle <= -2 * M_PI){
		angle = 0;
	}
	toDiffX= 6*(sin(angle));
	toDiffY= 6*(-cos(angle));
}

void Player::turnRight(){
	 angle += 0.1;
	 if (angle >= 2 * M_PI){
		 angle = 0;
	 }
	 toDiffX= 6*(sin(angle));
	 toDiffY= 6*(-cos(angle));;
}



} /* namespace RayCaster */

