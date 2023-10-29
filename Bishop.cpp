#include "Bishop.h"
#include "PrimativeGameObject.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

void Bishop::DrawGeometry()
{


	//__Cube__//
	glTranslatef(0, 0, 1);
	glutSolidCube(0.5f);
}