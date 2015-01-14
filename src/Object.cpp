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

void Object::show(int where,int height,vector<double> &zBuffer,double distance) {
	int center = 600 /2;
	SDL_Texture *texture = textures->getTexture(100);
	for (int i=0;i<height*2;i++)
	{
		SDL_Rect src,dst;
		src.x=(i/(double)height/2) * 64;
		src.y=0;
		src.w=1;
		src.h=64;

		int slice = where - i + height;
		dst.x=slice;
		dst.y=center- height;
		dst.w=1;
		dst.h=height*2;
		if ((slice > 0) && (slice < 800) && (zBuffer[slice]>distance))
		{
			SDL_RenderCopy(render, texture, &src, &dst);
		}

	}



/*
	int center = 600/2;
	SDL_Rect src,dst;
	src.x=0;
	src.y=0;
	src.w=64;
	src.h=64;

	dst.x=where - height;
	dst.y=center-height;
	dst.w=height*2;
	dst.h=height*2;
	SDL_Texture *texture = textures->getTexture(100);
	SDL_RenderCopy(render, texture, &src, &dst);
*/
}

void Object::setDistanceToPlayer(int distance){
	distanceToPlayer = distance;
}

Object::~Object() {
	logger << log4cpp::Priority::DEBUG << "Class destroy";
}

} /* namespace RayCaster */
