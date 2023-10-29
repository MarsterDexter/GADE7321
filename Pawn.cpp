#include "Pawn.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

void Pawn::DrawGeometry()
{

	//__Cone__//

	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 0, 0);
	glutSolidCone(0.25f, 1, 8, 8);

	//__Sphere__//
	glTranslatef(0, 0, 1);
	glutSolidSphere(0.25f, 12, 12);
}
