#pragma once
#include "PeSistemaParticulas.h"
class PeSPFuego :
	public PeSistemaParticulas
{
public:
	PeSPFuego(vec3 origen, int maxParticulas, float vida, /*float varVida, flaot varTam*/float kvd);
	virtual ~PeSPFuego();

	virtual void update(GLfloat deltaTime);
	virtual void addFuerza(vec3 f);
};

