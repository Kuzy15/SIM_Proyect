#include "PeMundo.h"


PeMundo::PeMundo()
{
	
	vec3 origen;
	origen.x = 1; origen.y = 0; origen.z = 1;
	sistemasParticulas_.push_back(new PeSPExplosion(origen,1000,10.0, 0));
	vec3 g; g.x = 0; g.y = -9.8; g.z = 0;
	setGravedad(g);
	sistemasParticulas_.front()->addFuerza(gravedad_);
}


PeMundo::~PeMundo()
{
	for (auto w : sistemasParticulas_){
		delete w;
		w = nullptr;
	}
}

void PeMundo::simula(){

	for (auto w : sistemasParticulas_){
		for (auto p : w->getParticulas()){
			w->SimulaPasoParticula(p, 0.016);
			}
	}
}

void PeMundo::dibuja(){

	for (auto w : sistemasParticulas_){
		for (auto p : w->getParticulas()){
			p->dibuja();
		}
	}
}