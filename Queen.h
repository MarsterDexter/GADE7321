#pragma once
#include "PrimativeGameObject.h"

class Queen : public PrimativeGameObject
{
private:
	vec3 Scale;
public:
	void DrawGeometry() override;

};


