#pragma once
#include "PrimativeGameObject.h"

class Bishop : public PrimativeGameObject
{
private:
	vec3 Scale;
public:
	void DrawGeometry() override;

};
