#include "ChessBoard.h"

ChessBoard::ChessBoard(int x, int y)
{
	this->sizex = x;
	this->sizey = y;

	for (int x = 0; x < sizex; x++)
	{
		for (int y = 0; y < sizey; y++)
		{
			CCube[x][y] = new TextureCube();

		}
	}

}

ChessBoard::~ChessBoard()
{
	for (int x = 0; x < sizex; x++)
	{
		for (int y = 0; y < sizey; y++)
		{
			delete CCube[x][y];

		}
	}
}

void ChessBoard::step(TextureManager* texM)
{

	for (int x = 0; x < sizex; x++)
	{
		for (int y = 0; y < sizey; y++)
		{
			if ((x + y) % 2 == 0)
			{
				texM->useTexture("black");

			}
			else
			{
				texM->useTexture("white");
			}
			CCube[x][y]->setPosition(vec3(x, 0, y));
			CCube[x][y]->draw();

		}
	}

}