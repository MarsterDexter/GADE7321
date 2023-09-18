
#pragma once
#include "TextureManager.h"
#include "TextureCube.h"
#include "glm/glm.hpp"

using namespace glm;

class ChessBoard
{

	TextureCube* CCube[10][10];
	int sizex, sizey;

	//__Randomise--Y--Heught//
	public:
	ChessBoard(int x, int y);
	~ChessBoard();
	float RandomNum(float min, float max);
	//__Randomise--Y--Heught//


	//__Access--Manager__//
	void step(TextureManager* texM);
};

