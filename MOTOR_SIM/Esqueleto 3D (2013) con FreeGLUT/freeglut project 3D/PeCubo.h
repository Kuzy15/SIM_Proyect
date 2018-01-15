#pragma once
#include "PeSolidoRigido.h"

class PeCubo :
	public PeSolidoRigido
{

public:
	enum tipo { normal, madera };
	PeCubo(float tam, vec3 pos, float masa, PeCubo::tipo t);

	virtual ~PeCubo();

	tipo _t;
	GLfloat r, g, b;
};

