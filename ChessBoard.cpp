#include "ChessBoard.h"
#include <random>


ChessBoard::ChessBoard(int x, int y)
{
	this->sizex = x;
	this->sizey = y;

	for (int x = 0; x < sizex; x++)
	{
		for (int y = 0; y < sizey; y++)
		{
			CCube[x][y] = new TextureCube();


			

			CCube[x][y]->SetScale(vec3(1, RandomNum(0.5F, 1), 1));

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

float ChessBoard::RandomNum(float min, float max)
{
	std::random_device randomDev;
	std::uniform_int_distribution<int> unifInt_Dis(min, max);
	
	return unifInt_Dis(randomDev);
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