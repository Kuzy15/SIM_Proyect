#pragma once
#include "PeSolidoRigido.h"
class PeEsfera : public PeSolidoRigido
{
public:
	PeEsfera(float tam, vec3 pos, float masa, int sl, int st, color3f c = { 0.5, 0.5, 0.5, 1 });
	~PeEsfera();
};

