#pragma once
#include "PrimativeGameObject.h"

class Rook : public PrimativeGameObject
{
private:
	vec3 Scale;
public:
	void DrawGeometry() override;

};