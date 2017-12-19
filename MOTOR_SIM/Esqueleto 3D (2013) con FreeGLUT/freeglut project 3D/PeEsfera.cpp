#include "PeEsfera.h"


PeEsfera::PeEsfera(float tam, vec3 pos, float masa, int sl, int st, color3f c)
{
	rb_ = new PeRigidBody(tam, pos, masa);
	ob_ = new Esfera(tam, sl, st);
}


PeEsfera::~PeEsfera()
{
}
