#include "Bishop.h"
#include "PrimativeGameObject.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

void Bishop::DrawGeometry()
{

	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 0, 0);
	glutSolidCone(0.25f, 1, 8, 8);

	//__Cube__//
	glTranslatef(0, 0, 1);
	glutSolidCube(0.5f);
}