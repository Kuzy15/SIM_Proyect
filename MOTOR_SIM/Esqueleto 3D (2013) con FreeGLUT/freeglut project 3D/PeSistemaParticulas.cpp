#include "PeSistemaParticulas.h"


PeSistemaParticulas::PeSistemaParticulas(vec3 origen, int maxParticulas, float vida, float kvd) :
origen_(origen), maxParticulas_(maxParticulas), vida_(vida), Kvd_(kvd)
{
	
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
