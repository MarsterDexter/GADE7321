#include "King.h"
#include "PrimativeGameObject.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>


void King::DrawGeometry()
{
	

	//__Cone__//

	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 0, 0);
	glutSolidCone(0.25f, 1, 8, 8);

	//__Sphere__//
	glTranslatef(0, 0, 1);
	glutSolidSphere(0.25f, 12, 12);

	//__Sphere__//
	glTranslatef(0, 0, 0);
	glutSolidCube(0.5f);

	//__Triangle__//
	glTranslatef(0, 0, 0.5f);
	glutSolidSphere(0.2f, 10, 10);

}


