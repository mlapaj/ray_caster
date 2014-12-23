/*

 * main.cpp
 *
 *  Created on: 23 gru 2014
 *      Author: lapajmar
 */

#include <iostream>
#include <memory>
#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>

#include <SDL.h>
#include "Game.h"

using namespace log4cxx;

int main()
{
	BasicConfigurator::configure();
	log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger());
	logger->setLevel(log4cxx::Level::getAll());
	LOG4CXX_INFO(logger, "Starting game.");
	RayCaster::Game oGame;
	LOG4CXX_INFO(logger, "Ending game game.");
	return 0;
}
