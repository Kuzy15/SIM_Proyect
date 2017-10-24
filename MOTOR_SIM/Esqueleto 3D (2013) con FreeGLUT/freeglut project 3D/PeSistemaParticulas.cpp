#include "PeSistemaParticulas.h"


PeSistemaParticulas::PeSistemaParticulas()
{
	vec3 pos;
	pos.x = 1;
	pos.y = 1;
	pos.z = 1;
	particulas_.push_back(new PeParticula(2, 2, pos, pos));
}


PeSistemaParticulas::~PeSistemaParticulas()
{
}

void const PeSistemaParticulas::addParticula(PeParticula* nPeParticula){

	particulas_.push_back(nPeParticula);

}

void PeSistemaParticulas::dibuja(){

	for (PeParticula* w : particulas_){
		w->dibuja();
	}
}