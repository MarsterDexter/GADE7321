#include "Knight.h"
#include "PrimativeGameObject.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

void Kinght::DrawGeometry()
{

	glTranslatef(0, 0.5f, 0);
	glutSolidSphere(0.3, 10, 10);

	glTranslatef(0, -0.5f, 0);
	glutSolidSphere(0.2, 10, 10);


}
