#ifndef PESPEXPLOSION
#define PESPEXPLOSION

#include "PeSistemaParticulas.h"

class PeSPExplosion :
	public PeSistemaParticulas
{
public:
	PeSPExplosion(vec3 origen, int maxParticulas, float vida, /*float varVida, flaot varTam*/float kvd);
	virtual ~PeSPExplosion();

	
	virtual void update(GLfloat deltaTime);
	virtual void addFuerza(vec3 f);
private:
};

#endif