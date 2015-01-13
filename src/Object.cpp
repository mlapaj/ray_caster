/*
 * Object.cpp
 *
 *  Created on: 30 gru 2014
 *      Author: lapajmar
 */

#include "Object.h"

namespace RayCaster {

SDL_Renderer *Object::render = nullptr;
shared_ptr<Textures> Object::textures;

Object::Object() {
	logger << log4cpp::Priority::DEBUG << "Class create";

}

void Object::setRender(SDL_Renderer *render)
{
	if (Object::render == nullptr)
	{
		Object::render = render;
	}
}

void Object::setTextures(shared_ptr<Textures> textures){
	Object::textures = textures;
}

void Object::show(int where,int height) {
	int center = 600/2;
	SDL_Rect src,dst;
	src.x=0;
	src.y=0;
	src.w=64;
	src.h=64;

	dst.x=where - 64;
	dst.y=center-height;
	dst.w=height*2;
	dst.h=height*2;
	SDL_Texture *texture = textures->getTexture(100);
	SDL_RenderCopy(render, texture, &src, &dst);
}

Object::~Object() {
	logger << log4cpp::Priority::DEBUG << "Class destroy";
}

} /* namespace RayCaster */
