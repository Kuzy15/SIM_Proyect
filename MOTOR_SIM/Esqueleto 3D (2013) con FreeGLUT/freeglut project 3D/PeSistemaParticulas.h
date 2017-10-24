#ifndef PESISTEMAPARTICULAS_H
#define PESISTEMAPARTICULAS_H


#include <list>
#include "PeParticula.h"
using namespace std;

class PeSistemaParticulas
{
private:

	list<PeParticula*> particulas_;

	int maxParticulas_;

	float vida_;

	float varVida_;

	float varTam_;

public:
	PeSistemaParticulas();
	virtual ~PeSistemaParticulas();

	void const addParticula(PeParticula*);

	void dibuja();

};

#endif