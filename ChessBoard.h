
#pragma once
#include "TextureManager.h"
#include "TextureCube.h"
#include "glm/glm.hpp"

using namespace glm;

class ChessBoard
{

	TextureCube* CCube[10][10];
	int sizex, sizey;

public:
	ChessBoard(int x, int y);
	~ChessBoard();

	void step(TextureManager* texM);
};

