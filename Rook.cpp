#include "Rook.h"
#include "PrimativeGameObject.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

void Rook::DrawGeometry()
{
	//__Cone__//

	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 1, 0);
	glutSolidCone(0.25f, 1, 8, 8);


	//__Sphere__//
	glTranslatef(0, 0, 0.5f);
	glutSolidCube(0.5f);
}

