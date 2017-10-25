#ifndef PESPEXPLOSION
#define PESPEXPLOSION

#include "PeSistemaParticulas.h"

class PeSPExplosion :
	public PeSistemaParticulas
{
public:
	PeSPExplosion(vec3 origen, int maxParticulas, float vida, /*float varVida, flaot varTam*/float kvd);
	virtual ~PeSPExplosion();

	virtual bool SimulaPasoParticula(PeParticula*p, vec3  a, float deltaTime);
	virtual bool SimulaPasoParticula(PeParticula*p, float deltaTime);
	virtual void addFuerza(vec3 f);
};

#endif