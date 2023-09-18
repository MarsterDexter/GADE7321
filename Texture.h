#pragma once
#include "Pixel.h"
#include "stb/stb_image.h"

class Texture
{
	public:
		//__HeightMap--Colors__//
		Texture(const char* path, int desiredChannels = 4);

		
		//__Deconstructor(Destructor)--"Textures"__//
		~Texture();

		//__Sets--X--Y__//
		void use();
		Pixel getPixelAt(int x, int y);

		//__Gets--Height--Width--Of--Texture__//
		int getWidth();
		int getHeight();

	private:

		//__Sotes--Image--In--Char--Array__//
		unsigned char* image;

		int width;
		int height;
		int channels;
		int desiredChannels;

		//__Tells--Us--If--The--Image--Is--Loaded--Already__//
		bool loaded = false;

		//__Loads__Texture__Into__Memeory__//
		void loadTexture(const char* path);

};

