/*
 * renderEngine.cpp
 *
 *  Created on: 16 gru 2014
 *      Author: lapajmar
 */

#include "renderEngine.h"
#include <cmath>
#define deg2rad(x) ((x) * M_PI / 180.0)

renderEngine::renderEngine(int resX, int resY, int fov, shared_ptr<map> rMap):oMap(rMap) {

	 //Create window
	 window = SDL_CreateWindow( "SDL Tutorial", 100, 100, resX, resY, SDL_WINDOW_SHOWN );
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


	this->resX = resX;
	this->resY = resY;
	this->fov = fov * M_PI / 180.0 ;
	this->halfFov = this->fov / 2;
	this->angleBetweenRays =  (fov / (double)this->resX)  * M_PI / 180.0;
	dToProjectionPlane = (resX/2)  / tan(this->fov/2);
	cout << "screen resolution: " << resX << "x" << resY << endl;
	cout << "distance to proj plane: " << dToProjectionPlane << endl;
	cout << "angle Between rays: " << this->angleBetweenRays << endl;
	// this should be changed when map block size will change from level to level
	mapBlockSize = rMap->getMapBlockSize();
}

void renderEngine::drawFrame(){
	SDL_SetRenderDrawColor(render,0,0,0,0);
	SDL_RenderClear(render);
	objectPosition pos;
	pos.x = 256;
	pos.y = 256;

    double i = 0;
	int z = 0;
	for (i=debugAngle-halfFov;i<debugAngle+halfFov;i+=angleBetweenRays)
	{
		z++;
		pos.angle = i;
		objectPosition posOutH;
		objectPosition posOutV;

		posOutH = castRayHorizontally(pos);
		posOutV = castRayVeritically(pos);

		//cout << "H: "<<posOutH.distance << "V:" << posOutV.distance << endl;
		if (posOutH.distance < posOutV.distance)
		{
			SDL_SetRenderDrawColor(render,0,255,0,0);
			SDL_RenderDrawLine(render,pos.x,pos.y,posOutH.x,posOutH.y);
		}
		else
		{

			SDL_SetRenderDrawColor(render,255,0,0,0);
			SDL_RenderDrawLine(render,pos.x,pos.y,posOutV.x,posOutV.y);
		}
		//SDL_SetRenderDrawColor(render,0,255,0,0);
		//SDL_RenderDrawLine(render,pos.x,pos.y,posOutH.x,posOutH.y);

	}


	SDL_RenderPresent(render);
}

renderEngine::~renderEngine() {
	//Destroy window
	SDL_DestroyWindow( window );
}


// its ok
objectPosition renderEngine::castRayHorizontally(objectPosition pos)
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
		//cout << pos.x + deltaXa << endl;
		if (oMap->isWallOnPosition(pos.x + deltaXa,pos.y + deltaYa))
		{
			break;
		}

	}
	pos.distance = sqrt((deltaXa*deltaXa) + (deltaYa*deltaYa));
	pos.x = pos.x + deltaXa;
	pos.y = pos.y + deltaYa;
	return pos;
}


// its not ok
objectPosition renderEngine::castRayVeritically(objectPosition pos)
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
	long oldDeltaXa = 0;
	long oldDeltaYa = 0;
	bool wallFoun = false;
	// first coordinates
	for (int i=0;i<debugRow;i++)
		{
			oldDeltaXa = deltaXa;
			oldDeltaYa = deltaYa;

			if (((angle > 0) && (angle < M_PI)) || // 0 to 180
				((angle < -M_PI) && (angle > 2*-M_PI))) // -180 to -360
			{
				if (0 == i)
				{
					deltaXa += (pos.x - int(pos.x / mapBlockSize) * mapBlockSize) +1;
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
					deltaXa += (pos.x - int(pos.x / mapBlockSize  + 1) * mapBlockSize) -1;
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

			if (oMap->isWallOnPosition(pos.x + deltaXa,pos.y + deltaYa))
			{
				bool wallFound = true;
				break;
			}
		}
	    pos.distance = sqrt((deltaXa*deltaXa) + (deltaYa*deltaYa));
		pos.x = pos.x + deltaXa;
		pos.y = pos.y + deltaYa;

	return pos;
}
