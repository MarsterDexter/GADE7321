#include "TextureCube.h"
#include <GL/freeglut.h>
#include "glm/glm.hpp"

using namespace glm;


//__Draws--Geometry--For--CCubes__//
void TextureCube::drawGeometry() 
{
    float s = 0.5F;

    glBegin(GL_QUADS); 
    {
        //__Front--Face__//
        glColor3f(1, 1, 1);
        glTexCoord2f(0, 0);
        glVertex3f(-0.5, -0.5, 0.5);

        glTexCoord2f(1, 0);
        glVertex3f(0.5, -0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex3f(0.5, 0.5, 0.5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.5, 0.5, 0.5);

        //__Back--Face__//
        glTexCoord2f(0, 0);
        glVertex3f(0.5, -0.5, -0.5);

        glTexCoord2f(1, 0);
        glVertex3f(-0.5, -0.5, -0.5);

        glTexCoord2f(1, 1);
        glVertex3f(-0.5, 0.5, -0.5);

        glTexCoord2f(0, 1);
        glVertex3f(0.5, 0.5, -0.5);

        //__Left--Face__//
        glTexCoord2f(0, 0);
        glVertex3f(-0.5, -0.5, -0.5);

        glTexCoord2f(1, 0);
        glVertex3f(-0.5, -0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex3f(-0.5, 0.5, 0.5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.5, 0.5, -0.5);

        //__Right--Face__//
        glTexCoord2f(0, 0);
        glVertex3f(0.5, -0.5, 0.5);

        glTexCoord2f(1, 0);
        glVertex3f(0.5, -0.5, -0.5);

        glTexCoord2f(1, 1);
        glVertex3f(0.5, 0.5, -0.5);

        glTexCoord2f(0, 1);
        glVertex3f(0.5, 0.5, 0.5);

        //__Top--Face__//
        glTexCoord2f(0, 0);
        glVertex3f(-0.5, 0.5, 0.5);

        glTexCoord2f(1, 0);
        glVertex3f(0.5, 0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex3f(0.5, 0.5, -0.5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.5, 0.5, -0.5);

        //__Bottom--Face__//
        glTexCoord2f(0, 0);
        glVertex3f(-0.5, -0.5, -0.5);

        glTexCoord2f(1, 0);
        glVertex3f(0.5, -0.5, -0.5);

        glTexCoord2f(1, 1);
        glVertex3f(0.5, -0.5, 0.5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.5, -0.5, 0.5);
    }
    glEnd();
}
