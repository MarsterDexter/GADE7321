#pragma once
#include <glm/glm.hpp> 

using namespace glm;

class PrimativeGameObject
{
private:
	vec3 Position;
	vec3 Scale = vec3(1, 1, 1);
	vec3 Rotation = vec3(0, 0, 0);
	virtual void DrawGeometry();

public:
	vec3 GetPosition();
	void SetScale(float x, float y, float z);
	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void Draw();
};

