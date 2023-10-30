#pragma once

#include "PrimativeGameObject.h"

class Kinght : public PrimativeGameObject
{
private:
	vec3 Scale;
public:
	void DrawGeometry() override;

};


