
#pragma once
#include "TextureManager.h"
#include "TextureCube.h"
#include "glm/glm.hpp"

using namespace glm;

class ChessBoard
{
private:
	vec3 Position;
	//__Sets--ChessBoard--In--An--Array__//
	TextureCube* CCube[10][10];
	int sizex, sizey, sizeb;
	//__Sets--ChessBoard--In--An--Array__//


	//__Randomise--Y--Heught//
	public:
	ChessBoard(int x, int y);
	~ChessBoard();
	float RandomNum(float min, float max);
	//__Randomise--Y--Heught//


	void SetPosition(float x, float y, float z);

	void ChessBoarder();
	//__Access--Manager__//
	void step(TextureManager* texM);
};

