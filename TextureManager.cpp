#include "TextureManager.h"
#include <iostream>

using namespace std;

//__Load--Height--Map__// 

TextureManager::TextureManager()
{
	//__Access--Texture--Folder--Referencing--The--PNG's--Name__//
	textures.insert({ "black", new Texture("Textures/black.png") }); //__Black--Texture__//
	textures.insert({ "white", new Texture("Textures/white.png") });//__White--Texture__//
	textures.insert({ "heightMap", new Texture("Textures/Test.png") }); //__Height--Map__//
	textures.insert({ "wood", new Texture("Textures/wood_grain.png") }); //__Wood--GrainTexture__//


	textures.insert({ "Boat", new Texture("Model/Boat/boat.jpg") }); //__Boat--Texture__//
	textures.insert({ "Table", new Texture("Model/Table/Table.jpg") }); //__Table--Texture__//
	textures.insert({ "water", new Texture("Model/water/water.jpg") }); //__Table--Texture__//
	textures.insert({ "sky", new Texture("Model/sky/sky.jpg") }); //__Table--Texture__//
	textures.insert({ "scale", new Texture("Model/scale/scale.jpg") }); //__Table--Texture__//
	textures.insert({ "osiris", new Texture("Model/osiris/osiris.jpg") }); //__Table--Texture__//
	textures.insert({ "anbus", new Texture("Model/anbus/anbus.jpg") }); //__Table--Texture__//
	
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
