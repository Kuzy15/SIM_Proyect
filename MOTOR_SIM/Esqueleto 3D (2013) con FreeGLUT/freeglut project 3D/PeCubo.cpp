#include "PeCubo.h"

PeCubo::PeCubo(float tam, vec3 pos, float masa, PeCubo::tipo t)
{
	_t = t;
	if (t == PeCubo::normal) {
		r = 0;
		g = 0.5;
		b = 0.5;
		ob_ = new Cubo(tam, r, g, b, 'n');
	}

	else {
		r = 0.2;
		g = 0.1;
		b = 0.1;
		ob_ = new Cubo(tam, r, g, b, 'm');
	}
	rb_ = new PeRigidBody(tam, pos, masa);




}


PeCubo::~PeCubo()
{
}
