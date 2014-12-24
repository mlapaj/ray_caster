/*
 * Textures.h
 *
 *  Created on: 24 gru 2014
 *      Author: lapajmar
 */

#ifndef TEXTURES_H_
#define TEXTURES_H_
#include <map>
#include <SDL.h>

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"

using namespace std;
namespace RayCaster {

class Textures {
private:
	const string textureDirectory = "textures/";
	log4cpp::Category& logger = log4cpp::Category::getInstance("Textures");
	map<int,SDL_Surface*> surfaces;
	map<int,SDL_Texture*> textures;
	SDL_Renderer *render;
public:
	Textures(SDL_Renderer *render);
	SDL_Texture *getTexture(int i);
	virtual ~Textures();
};

} /* namespace RayCaster */

#endif /* TEXTURES_H_ */
