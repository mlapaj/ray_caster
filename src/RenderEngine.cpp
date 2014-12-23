/*
 * renderEngine.cpp
 *
 *  Created on: 16 gru 2014
 *      Author: lapajmar
 */

#include "RenderEngine.h"

#include <cmath>
#define deg2rad(x) ((x) * M_PI / 180.0)

RenderEngine::RenderEngine(int resX, int resY, int fov, shared_ptr<RayCaster::Map> rMap):oMap(rMap) {

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
	dToProjectionPlane = (resX/2)  / tan(this->halfFov);
	cout << "screen resolution: " << resX << "x" << resY << endl;
	cout << "distance to proj plane: " << dToProjectionPlane << endl;
	cout << "angle Between rays: " << this->angleBetweenRays << endl;
	// this should be changed when map block size will change from level to level
	mapBlockSize = rMap->getMapBlockSize();
}


void RenderEngine::drawFrame(){

	temp = SDL_LoadBMP("tex2.bmp");
	if (temp == NULL) {
		cout << "error!";
		return;
	}
	texture = SDL_CreateTextureFromSurface(render, temp);


	//debugPlane();
	//return;
	// to fix
	if ((oMap->getWidth()) / oMap->getMapBlockSize() > (oMap->getHeight() / oMap->getMapBlockSize()))
	{
		debugRow = (oMap->getWidth() / oMap->getMapBlockSize()) +1;
	}
	else
	{
		debugRow = (oMap->getHeight() / oMap->getMapBlockSize()) +1;
	}
	SDL_SetRenderDrawColor(render,0,0,0,0);
	SDL_RenderClear(render);
	ObjectPosition pos;
	pos.x = debugPlayerPositionX + diffX;
	pos.y = debugPlayerPositionY + diffY;

	double i = debugAngle;
	ObjectPosition posOutH;
	ObjectPosition posOutV;
	ObjectPosition *posCloser;
	int z=0;
	for (i=debugAngle-halfFov;i<debugAngle+halfFov;i+=angleBetweenRays)
	{
		z++;
		pos.angle = i;


		posOutH = castRayHorizontally(pos);
		posOutV = castRayVeritically(pos);
        posCloser = &posOutV;

		if (posOutH.distance < posOutV.distance)
		{
			SDL_SetRenderDrawColor(render,0,255,0,0);
			posCloser = &posOutH;
		}
		else
		{
			SDL_SetRenderDrawColor(render,255,0,0,0);
			posCloser = &posOutV;
		}
		cout << "texture slice" << posCloser->sliceNo << endl;
		// slice height = actual slice height / distance to slice * distance to projection plane

		double distanceToSlice = 0;

		distanceToSlice = (double)posCloser->distance * cos(i-debugAngle);

		double sliceHeight = (oMap->getMapBlockSize() / distanceToSlice ) * dToProjectionPlane;
		//cout << "cos z" << (i-debugAngle) * 180 / M_PI << endl;

		drawSlice(z,sliceHeight,posCloser->sliceNo);
	}
	cout << "Z is:" << z <<endl;




	SDL_RenderPresent(render);
}

void RenderEngine::drawSlice(int which,int height,int sliceNo){

	int center = resY / 2;


	SDL_Rect src,dst;
	src.x=0+sliceNo;
	src.y=0;
	src.w=1;
	src.h=64;

	dst.x=which;
	dst.y=center-height;
	dst.w=1;
	dst.h=height*2;
	SDL_RenderCopy(render, texture, &src, &dst);

	//SDL_RenderDrawLine(render,which,center-height,which,center+height);
}


void RenderEngine::debugForward(){
	toDiffX= sin(debugAngle);
	toDiffY= -cos(debugAngle);
	diffX += toDiffX *3;
	diffY += toDiffY *3;
}

void RenderEngine::debugBackward(){
	toDiffX= sin(debugAngle);
	toDiffY= -cos(debugAngle);
	diffX -= toDiffX * 3;
	diffY -= toDiffY * 3;
}



void RenderEngine::debugPlane()
{
	SDL_SetRenderDrawColor(render,0,0,0,0);
	SDL_RenderClear(render);
	SDL_SetRenderDrawColor(render,255,0,0,0);
	SDL_RenderDrawPoint(render,100+diffX*3,100+diffY*3);

	SDL_RenderPresent(render);
}

void RenderEngine::debugDrawFrame(){
	SDL_SetRenderDrawColor(render,0,0,0,0);
	SDL_RenderClear(render);
	ObjectPosition pos;
	pos.x = 256;
	pos.y = 256;

	double i = 0;
	ObjectPosition posOutH;
	ObjectPosition posOutV;
	ObjectPosition *posCloser;

	for (i=debugAngle-halfFov;i<debugAngle+halfFov;i+=angleBetweenRays)
	{
		pos.angle = i;



		posOutH = castRayHorizontally(pos);
		posOutV = castRayVeritically(pos);
		if (posOutH.distance < posOutV.distance)
		{
			SDL_SetRenderDrawColor(render,0,255,0,0);
			posCloser = &posOutH;
		}
		else
		{
			SDL_SetRenderDrawColor(render,255,0,0,0);
			posCloser = &posOutV;
		}
		;
		SDL_RenderDrawLine(render,pos.x,pos.y,posCloser->x,posCloser->y);
	}
	SDL_RenderPresent(render);
}

RenderEngine::~RenderEngine() {
	//Destroy window
	SDL_DestroyWindow( window );
}


// its ok
ObjectPosition RenderEngine::castRayHorizontally(ObjectPosition pos)
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
		static wallPositionDetails detail;
		if (oMap->isWallOnPosition(pos.x + deltaXa,pos.y + deltaYa,&detail))
		{
			pos.sliceNo = (pos.x + deltaXa) % mapBlockSize;
			//cout << "sliceH:" << pos.sliceNo << endl;
			break;
		}

	}
	pos.distance = sqrt((deltaXa*deltaXa) + (deltaYa*deltaYa));
	pos.x = pos.x + deltaXa;
	pos.y = pos.y + deltaYa;
	return pos;
}


// its not ok
ObjectPosition RenderEngine::castRayVeritically(ObjectPosition pos)
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
			static wallPositionDetails detail;
			if (oMap->isWallOnPosition(pos.x + deltaXa,pos.y + deltaYa,&detail))
			{
				pos.sliceNo = (pos.y + deltaYa) % mapBlockSize;
				//cout << "sliceV:" << pos.sliceNo << endl;
				break;
			}
		}
	    pos.distance = sqrt((deltaXa*deltaXa) + (deltaYa*deltaYa));
		pos.x = pos.x + deltaXa;
		pos.y = pos.y + deltaYa;

	return pos;
}