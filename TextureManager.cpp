#include "TextureManager.h"
#include <iostream>

using namespace std;

//__Load--Height--Map__// 

TextureManager::TextureManager()
{
	//__Access--Texture--Folder--Referencing--The--PNG's--Name__//
	textures.insert({ "black", new Texture("Textures/black.png") }); //__Black--Texture__//
	textures.insert({ "white", new Texture("Textures/white.png") });//__White--Texture__//
	textures.insert({ "heightMap", new Texture("Textures/heightMap.png") }); //__Height--Map__//
}

TextureManager::~TextureManager()
{	
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
		cout << "Not available" << endl;
		return;
	}

	Texture* tex = textures[textureName];
	tex->use();
}

Texture* TextureManager::getTexture(string textureName)
{
	return textures[textureName];
}
