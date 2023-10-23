#include "PrimativeGameObject.h"
#include <GL/freeglut.h>
#include <iostream>

void PrimativeGameObject::DrawGeometry()
{
    Draw();
}

void PrimativeGameObject::SetScale(float x, float y, float z)
{
    Scale = vec3(x, y, z);
}

void PrimativeGameObject::SetPosition(float x, float y, float z)
{
    Position = vec3(x, y, z);
}

void PrimativeGameObject::Draw()
{
    glEnable(GL_DEPTH_TEST);


    glPushMatrix();
    {
        glTranslatef(Position.x, Position.y, Position.z);


        if (Scale.x <= 0 || Scale.y <= 0 || Scale.z <= 0)
        {
            Scale = vec3(1, 1, 1);
        }

        glScalef(Scale.x, Scale.y, Scale.z);


        DrawGeometry();

    }

    glPopMatrix();
}