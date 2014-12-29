/*
 * renderEngine.h
 *
 *  Created on: 16 gru 2014
 *      Author: lapajmar
 */

#ifndef RENDERENGINE_H_
#define RENDERENGINE_H_
#include <memory>
#include <SDL.h>
#include "Map.h"
#include "Player.h"
#include "Textures.h"

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"

namespace RayCaster
{
	class RenderEngine {
	public:
		int debugRow = 1;
		RenderEngine(int resX,int resY,int fov,shared_ptr<RayCaster::Map> rMap,shared_ptr<Player> player);
		void drawFrame();
		void drawSlice(int which,int height,int sliceNo,int textureNo);
		virtual ~RenderEngine();
	private:
		SDL_Rect src,dst;
		shared_ptr<Player> player;
		log4cpp::Category& logger = log4cpp::Category::getInstance("RenderEngine");
		int mapBlockSize;
		int resX;
		int resY;
		SDL_Window* window = NULL;
		SDL_Renderer *render;
		int dToProjectionPlane;

		double fov; // in radians
		double halfFov;
		double angleBetweenRays; // in radians
		shared_ptr<RayCaster::Map> oMap;
		void castRayHorizontally(ObjectPosition pos,CastInfo &castInfo);
		void castRayVeritically(ObjectPosition pos,CastInfo &castInfo);
		shared_ptr<RayCaster::Textures> textures;
	};
}
#endif /* RENDERENGINE_H_ */
