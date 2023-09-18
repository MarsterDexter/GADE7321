#include "TextureManager.h"
#include <iostream>

using namespace std;

//use game obejct class - extend it to create terrain game object and in there load heigthmap texture 

//add more textures here for applying to 3D models
TextureManager::TextureManager()
{

	textures.insert({ "black", new Texture("Textures/black.png") });
	textures.insert({ "white", new Texture("Textures/white.png") });
}

TextureManager::~TextureManager()
{	
	//freeing up memeory to avoid memory leaks
	map<string, Texture*>::iterator it;

	for (it = textures.begin(); it != textures.end(); it++)
	{
		delete it->second;
	}
}

void TextureManager::useTexture(string textureName)
{
	if (!textures.count(textureName))
	{
		cout << "WARNING: Texture does not exist!" << endl;
		return;
	}

	Texture* tex = textures[textureName];
	tex->use();
}

Texture* TextureManager::getTexture(string textureName)
{
	return textures[textureName];
}
