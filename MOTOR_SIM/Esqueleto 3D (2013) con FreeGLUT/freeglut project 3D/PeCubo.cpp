#include "PeCubo.h"

PeCubo::PeCubo(float tam, vec3 pos, float masa, color3f c )
{
	rb_ = new PeRigidBody(pos, masa);
	ob_ = new Cubo(tam);
}


PeCubo::~PeCubo()
{
}
