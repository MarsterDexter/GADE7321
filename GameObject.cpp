#include "GameObject.h"
#include <GL/freeglut.h>
#include <iostream>
#include <math.h>



void GameObject::setPosition(vec3 position)
{
	this->position = position;
}

void GameObject::setRotation(vec3 rotation)
{
	this->rotation = rotation;
}

void GameObject::SetScale(vec3 scale)
{
	this->scale = scale;
}

vec3 GameObject::getPosition()
{
	return position;
}

vec3 GameObject::normalised()
{
	float x = sqrt(position.x);
	float y = sqrt(position.y);
	float z = sqrt(position.z);

	return vec3(x, y, z);
}

void GameObject::draw()//__DrawMethod--Draws--Verticies__//
{
	glEnable(GL_DEPTH_TEST);


	glPushMatrix();
	{
		glTranslatef(position.x, position.y, position.z);

		glRotatef(rotation.x, 1, 0, 0);
		glRotatef(rotation.y, 0, 1, 0);
		glRotatef(rotation.z, 0, 0, 1);

		glScalef(scale.x, scale.y, scale.z);

		drawGeometry();
	
		
	
	}
	glPopMatrix();
	
}

void GameObject::drawGeometry()
{
}

void GameObject::drawOrigin()
{
	//_Draw--On--Top--Over--Everything__//
	glDisable(GL_DEPTH_TEST);

	glBegin(GL_LINES);
	{
		//__Sets--X--To--Red__//
		glColor3f(1, 0, 0);
		
		glVertex3f(0, 0, 0);
		glVertex3f(originSize, 0, 0);

		//__Sets--Y--To--Green__//
		glColor3f(0, 1, 0);
		
		glVertex3f(0, 0, 0);
		glVertex3f(0, originSize, 0);

		//__Sets--Z--To--Blue__//
		glColor3f(0, 0, 1);
		
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, originSize);


	
	}
	glEnd();

	glPushMatrix();
	{
		glColor3f(1, 0, 0);
		glTranslatef(originSize, 0, 0);
		glRotatef(90, 0, 1, 0);
		glutSolidCone(0.05, 0.2, 8, 1);

	}
	glPopMatrix();

	glEnable(GL_DEPTH_TEST);

	
	glPushMatrix();
	{
		glColor3f(0, 1, 0);
		glTranslatef(0, originSize, 0);
		glRotatef(-90, 1, 0, 0);
		glutSolidCone(0.05, 0.2, 8, 1);

	}
	glPopMatrix();

	
	glPushMatrix();
	{
		glColor3f(0, 0, 1);
		glTranslatef(0, 0, originSize);
		glRotatef(0, 0, 0, 0);
		glutSolidCone(0.05, 0.2, 8, 1);

	}
	glPopMatrix();

	
}

void GameObject::generateDisplayList()
{
    displayListId = glGenLists(1);

    glNewList(displayListId, GL_COMPILE);
    {
        drawGeometry();
    }
    glEndList();

    displayListGenerated = true;
}

