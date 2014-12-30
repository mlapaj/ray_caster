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

void Object::show() {
	SDL_Rect src,dst;
	src.x=0;
	src.y=0;
	src.w=64;
	src.h=64;

	dst.x=0;
	dst.y=0;
	dst.w=128;
	dst.h=128;
	SDL_Texture *texture = textures->getTexture(100);
	SDL_RenderCopy(render, texture, &src, &dst);
}

Object::~Object() {
	logger << log4cpp::Priority::DEBUG << "Class destroy";
}

} /* namespace RayCaster */
