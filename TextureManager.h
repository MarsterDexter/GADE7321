#pragma once
#include <map>
#include <string>
#include "Texture.h"
#include "stb/stb_image.h"


using namespace std;

class TextureManager
{
	public:
		//__loads--All--Textures__//
		TextureManager();

		//__Destructs--"TextureManager"__//
		~TextureManager();

		//__Specify--Which--Texture--To--Use__//
		void useTexture(string textureName);

		Texture* getTexture(string textureName);

	private:
		map<string, Texture*> textures;
};

