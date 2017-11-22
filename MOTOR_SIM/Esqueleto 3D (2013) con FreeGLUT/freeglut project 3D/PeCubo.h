#pragma once
#include "PeSolidoRigido.h"

class PeCubo :
	public PeSolidoRigido
{
public:
	PeCubo(float tam, vec3 pos, float masa, color3f c = { 0.5, 0.5, 0.5, 1 });

	virtual ~PeCubo();
};

