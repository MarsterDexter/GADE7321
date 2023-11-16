#include "ChessBoard.h"
#include "GL\freeglut.h"
#include <random>
#include "GameObject.h"

GameObject* chessBoarder;

//__Creates--ChessBoard--And--Size__//
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

	ChessBoarder();
}

void ChessBoard::SetPosition(float x, float y, float z)
{
	Position = vec3(x, y, z);
}


void ChessBoard::ChessBoarder()					//__ChessBoarder__//
{
	chessBoarder = new TextureCube();
	glColor3f(0, 0, 0);
	chessBoarder->SetScale(vec3(10, 0.5f, 10));
	chessBoarder->setPosition(vec3(3.5F, -0.35F, 3.5F));

}

ChessBoard::~ChessBoard()				//__ChessBoarder--Deconstructor__//
{
	for (int x = 0; x < sizex; x++)
	{
		for (int y = 0; y < sizey; y++)
		{
			delete CCube[x][y];
		}
	}

	delete chessBoarder;
}

//__Randomises--Height__//
float ChessBoard::RandomNum(float min, float max)
{
	std::random_device randomDev;
	std::uniform_int_distribution<int> unifInt_Dis(min, max);
	
	return unifInt_Dis(randomDev);
}
//__Randomises--Height__//

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

	glDisable(GL_TEXTURE_2D);

	for (int x = 0; x < sizex; x++)
	{
		for (int y = 0; y < sizey; y++)
		{
			texM->useTexture("wood");

			chessBoarder->draw();
		}
	}

}