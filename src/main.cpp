/*

 * main.cpp
 *
 *  Created on: 23 gru 2014
 *      Author: lapajmar
 */

#include <iostream>
#include <memory>

#include <SDL.h>
#include "Game.h"


#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"


int main()
{
	log4cpp::Appender *appender1 = new log4cpp::OstreamAppender("console", &std::cout);
	appender1->setLayout(new log4cpp::BasicLayout());

	log4cpp::Appender *appender2 = new log4cpp::FileAppender("default", "program.log");
	appender2->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category& root = log4cpp::Category::getRoot();
	root.setPriority(log4cpp::Priority::DEBUG);
	root.addAppender(appender1);

	//log4cpp::Category& sub1 = log4cpp::Category::getInstance(std::string("sub1"));
	//sub1.addAppender(appender2);

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}

	root.info("Program starting...");
	RayCaster::Game oGame;
	oGame.mainLoop();
	SDL_Quit();
	return 0;
}
