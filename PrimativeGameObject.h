#pragma once
#include <glm/glm.hpp> 

using namespace glm;

class PrimativeGameObject
{
private:
	vec3 Position;
	vec3 Scale;
	virtual void DrawGeometry();

public:
	void SetScale(float x, float y, float z);
	void SetPosition(float x, float y, float z);
	void Draw();
};

