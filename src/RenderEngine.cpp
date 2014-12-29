/*
 * renderEngine.cpp
 *
 *  Created on: 16 gru 2014
 *      Author: lapajmar
 */

#include "RenderEngine.h"

#include <cmath>
#define deg2rad(x) ((x) * M_PI / 180.0)

RayCaster::RenderEngine::RenderEngine(int resX, int resY, int fov, shared_ptr<RayCaster::Map> rMap,shared_ptr<Player> player){

	 this->oMap = rMap;
	 this->player = player;
	 logger << log4cpp::Priority::DEBUG << "Class constructor";
	 //Create windowqqqq
	 window = SDL_CreateWindow( "SDL Tutorial", 00, 00, resX, resY,SDL_WINDOW_SHOWN); //  // //  SDL_WINDOW_FULLSCREEN
	 if( window == NULL )
	 {
		 printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
	 }
	 else
	 {
		 render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		  if (render == nullptr){
			 	SDL_DestroyWindow(window);
			 	std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			 	SDL_Quit();
			 	return;
			 }

	 }
	textures.reset(new Textures(render));

	this->resX = resX;
	this->resY = resY;
	this->fov = fov * M_PI / 180.0 ;
	this->halfFov = this->fov / 2;
	this->angleBetweenRays =  (this->fov / (double)this->resX);
	dToProjectionPlane = (resX/2)  / tan(this->halfFov);
	cout << "screen resolution: " << resX << "x" << resY << endl;
	cout << "distance to proj plane: " << dToProjectionPlane << endl;
	cout << "angle Between rays: " << this->angleBetweenRays << endl;
	// this should be changed when map block size will change from level to level
	mapBlockSize = rMap->getMapBlockSize();

	// TODO
	if ((oMap->getWidth()) / oMap->getMapBlockSize() > (oMap->getHeight() / oMap->getMapBlockSize()))
	{
		debugRow = (oMap->getWidth() / oMap->getMapBlockSize()) +1;
	}
	else
	{
		debugRow = (oMap->getHeight() / oMap->getMapBlockSize()) +1;
	}



}


void RayCaster::RenderEngine::drawFrame(){
	static CastInfo castInfoV;
	static CastInfo castInfoH;
	static CastInfo *castInfoCloser;



	SDL_SetRenderDrawColor(render,128,128,128,0);
	SDL_Rect up,down;
   	up.x = 0;
   	up.y = 0;
   	up.w = resX;
   	up.h = resY/2;
   	down.x = 0;
   	down.y = resY/2;
   	down.w = resX;
   	down.h = resY/2;

   	SDL_SetRenderDrawColor(render,128,128,128,0);
	SDL_RenderFillRect(render,&up);
	SDL_SetRenderDrawColor(render,64,64,64,0);
	SDL_RenderFillRect(render,&down);

	ObjectPosition pos;
	pos.x = player->getPlayerPosX(); // + diffX;
	pos.y = player->getPlayerPosY(); // + diffY;

	double angle = player->getPlayerAngle();
	double i = angle;

	int z=0;
	for (i=angle-halfFov;i<angle+halfFov;i+=angleBetweenRays)
	{
		z++;
		pos.angle = i;


		castRayHorizontally(pos,castInfoH);
		castRayVeritically(pos,castInfoV);

		if (castInfoH.distance < castInfoV.distance)
		{
			SDL_SetRenderDrawColor(render,0,255,0,0);
			castInfoCloser = &castInfoH;
		}
		else
		{
			SDL_SetRenderDrawColor(render,255,0,0,0);
			castInfoCloser = &castInfoV;
		}

		double distanceToSlice = 0;
		// slice height = actual slice height / distance to slice * distance to projection plane
		distanceToSlice = (double)castInfoCloser->distance * cos(i-angle);
		// something wrong with height is !!!!!!!!!!
		double sliceHeight = ((oMap->getMapBlockSize()/2) / distanceToSlice ) * dToProjectionPlane;
		//cout << "cos z" << (i-debugAngle) * 180 / M_PI << endl;

		drawSlice(z,sliceHeight,castInfoCloser->sliceNo,castInfoCloser->textureNumber);
	}
	SDL_RenderPresent(render);
}

void RayCaster::RenderEngine::drawSlice(int which,int height,int sliceNo,int textureNo){

	int center = resY / 2;

	SDL_Rect src,dst;
	src.x= ((double)sliceNo / mapBlockSize) * 64;
	src.y=0;
	src.w=1;
	src.h=64;

	dst.x=which;
	dst.y=center-height;
	dst.w=1;
	dst.h=height*2;
	SDL_Texture *texture = textures->getTexture(textureNo);
	SDL_RenderCopy(render, texture, &src, &dst);
}



RayCaster::RenderEngine::~RenderEngine() {
	logger << log4cpp::Priority::DEBUG << "Class destructor";
	//Destroy window
	SDL_DestroyWindow( window );
}


// its ok
void RayCaster::RenderEngine::castRayHorizontally(ObjectPosition pos,CastInfo &castInfo)
{


	// we should normalize angle here
	double angle =  pos.angle;
    double tanAngle = tan(angle);
	long deltaYa = 0;
	long deltaXa = 0;
	// first coordinates
	if (angle > 2*M_PI){
		angle -= 2*M_PI;
	}

	if (angle < 2*-M_PI){
		angle += 2*M_PI;
	}

	if ((angle <= 3*-M_PI_2) && (angle >= 2*-M_PI)) // -270 to -360
	{
		angle = angle + 4*M_PI_2;
	}
	else if ((angle >= 3*M_PI_2) && (angle<= 2*M_PI)) // 270 to 360
	{
		angle = angle - 2*M_PI;
	}


	for (int i=0;i<debugRow;i++)
	{

		if ((angle >= -M_PI/2) && (angle <= M_PI/2)) // -90 to 90

		{
			if (0==i)
			{
				deltaYa += - (pos.y - (pos.y / mapBlockSize) * mapBlockSize) -1;
			}
			else
			{
				deltaYa += -mapBlockSize;
			}
			deltaXa = - (deltaYa * tanAngle);
		}
		else
		{
			if (0==i)
			{
				deltaYa += -(pos.y-(pos.y / mapBlockSize + 1) * mapBlockSize) +1;

			}
			else
			{
				deltaYa += mapBlockSize;
			}
			deltaXa = -(deltaYa * tan(angle));
		}
		// faster

		if (oMap->isWallOnPosition(pos.x + deltaXa,pos.y + deltaYa,castInfo))
		{
			castInfo.sliceNo = (pos.x + deltaXa) % mapBlockSize;
			//cout << "sliceH:" << pos.sliceNo << endl;
			break;
		}

	}
	castInfo.distance = sqrt((deltaXa*deltaXa) + (deltaYa*deltaYa));
}


// its not ok
void RayCaster::RenderEngine::castRayVeritically(ObjectPosition pos,CastInfo &castInfo)
{
	// we should normalize angle
	double angle =  pos.angle;
    double tanAngle = tan(angle);
	// first coordinates
	if (angle >= 2*M_PI){
		angle -= 2*M_PI;
	}

	if (angle <= 2*-M_PI){
		angle += 2*M_PI;
	}

	long deltaYa = 0;
	long deltaXa = 0;

	// first coordinates
	for (int i=0;i<debugRow;i++)
		{
			if (((angle > 0) && (angle < M_PI)) || // 0 to 180
				((angle < -M_PI) && (angle > 2*-M_PI))) // -180 to -360
			{
				if (0 == i)
				{
					deltaXa += -(pos.x - int(pos.x / mapBlockSize+1) * mapBlockSize) + 1;

					//cout << "pos" << pos.x << " deltaXa1: " << deltaXa << endl;
				}
				else
				{
					deltaXa += mapBlockSize;
				}

				deltaYa = -(deltaXa / tanAngle);
				if (deltaYa < -1000000){
					deltaYa = -1000000;
				}

			}
			else
			{
				if (0 == i)
				{
					deltaXa += -(pos.x - int(pos.x / mapBlockSize) * mapBlockSize) -1;
				}
				else
				{
					deltaXa += -mapBlockSize;
				};
				deltaYa = -(deltaXa / tanAngle);

				if (deltaYa < -1000000)
				{
					deltaYa = -1000000;
				}


			}
			// faster
			if (oMap->isWallOnPosition(pos.x + deltaXa,pos.y + deltaYa,castInfo))
			{
				castInfo.sliceNo = (pos.y + deltaYa) % mapBlockSize;
				//cout << "sliceV:" << pos.sliceNo << endl;
				break;
			}
		}
		castInfo.distance = sqrt((deltaXa*deltaXa) + (deltaYa*deltaYa));
}
