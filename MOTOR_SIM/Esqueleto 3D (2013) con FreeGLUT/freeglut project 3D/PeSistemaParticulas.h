#ifndef PESISTEMAPARTICULAS_H
#define PESISTEMAPARTICULAS_H


#include <list>
#include "PeParticula.h"
using namespace std;

class PeSistemaParticulas
{
protected:

	vec3 origen_;

	list<PeParticula*> particulas_;

	int maxParticulas_;

	float vida_;

	float varVida_;

	float varTam_;

	float Kvd_;

public:
	PeSistemaParticulas(vec3 origen, int maxParticulas, float vida, /*float varVida, flaot varTam*/float kvd);

	virtual ~PeSistemaParticulas();

	inline list<PeParticula*> getParticulas(){ return particulas_; };

	inline float getNumParticulas(){ return particulas_.size(); }

	void const addParticula(PeParticula*);

	virtual bool SimulaPasoParticula(PeParticula*p, vec3  a, float deltaTime) = 0;

	virtual bool SimulaPasoParticula(PeParticula*p, float deltaTime) = 0;

	virtual void addFuerza(vec3 f) = 0;

	void dibuja();

};

#endif