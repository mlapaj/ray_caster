/*
 * Object.h
 *
 *  Created on: 30 gru 2014
 *      Author: lapajmar
 */

#ifndef OBJECT_H_
#define OBJECT_H_


#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"


#include <memory>

#include "ObjectPositon.h"
#include "SDL.h"
#include "Textures.h"

using namespace std;

namespace RayCaster {

class Object: public ObjectPosition {
private:
	static SDL_Renderer *render;
	static shared_ptr<Textures> textures;
	log4cpp::Category& logger = log4cpp::Category::getInstance("Object");
public:
	int x,y;
	static void setRender(SDL_Renderer *render);
	static void setTextures(shared_ptr<Textures> textures);
	Object();
	void show(int where,int height);
	virtual ~Object();
};

} /* namespace RayCaster */

#endif /* OBJECT_H_ */
