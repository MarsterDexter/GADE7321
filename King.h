#pragma once
#include "PrimativeGameObject.h"

class King : public PrimativeGameObject
{
private:
	vec3 Scale;
public:
	void DrawGeometry() override;

};

