#include "Rook.h"
#include "PrimativeGameObject.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

void Rook::DrawGeometry()
{
	//__Cone__//

	glTranslatef(0, 1, 0.5f);
	glutSolidCube(0.5f);


	//__Sphere__//
	glTranslatef(0, 0, 0.5f);
	glutSolidCube(0.6f);
}

