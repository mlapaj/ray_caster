/*
 * Textures.cpp
 *
 *  Created on: 24 gru 2014
 *      Author: lapajmar
 */

#include "Textures.h"

#include <iostream>
#include <fstream>


namespace RayCaster {

Textures::Textures(SDL_Renderer *render) {
	this->render = render;
	logger << log4cpp::Priority::DEBUG << "Class constructor";
	string fileName(textureDirectory + "textures.dat");
	ifstream tekstury;
	tekstury.open(fileName.c_str());
	pair<int,SDL_Surface*> surf;
	pair<int,SDL_Texture*> tex;
	if (tekstury.is_open()){
		while (!tekstury.eof())
		{
			int i;
			string fileName;
			tekstury >> i;
			tekstury >> fileName;
			logger << log4cpp::Priority::DEBUG << "loaded [" << i << "]: " << fileName;
			SDL_Surface *tmpSurf = SDL_LoadBMP((textureDirectory + fileName).c_str());
			// transparent texture
			if (i>=100)
			{
				Uint32 colorkey = SDL_MapRGB( tmpSurf->format, 152, 0x0, 136 );
				SDL_SetColorKey( tmpSurf, SDL_TRUE, colorkey );
			}
			SDL_Texture *tmpTex = SDL_CreateTextureFromSurface(this->render, tmpSurf);

			surf.first = i;
			surf.second = tmpSurf;
			tex.first = i;
			tex.second = tmpTex;
			surfaces.insert(surf);
			textures.insert(tex);

		}
	}
	else
	{
		logger << log4cpp::Priority::ERROR << "Failed to open texture datafile";
	}

}

SDL_Texture *Textures::getTexture(int i){
	return textures[i];
}

Textures::~Textures() {
	logger << log4cpp::Priority::DEBUG << "Class destructor";
}

} /* namespace RayCaster */
