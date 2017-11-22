#include "PeMundo.h"
#include "PeSPExplosion.h"
#include "PeSPFuego.h"

PeMundo::PeMundo()
{
	
	
	origen.x = 0; origen.y = 0; origen.z = 0;
	//explo = new PeSPExplosion(origen, 5000, 100.0, 0);
	explo = new PeSPFuego(origen, 5000, 10.0f, 0);
	sistemasParticulas_.push_back(explo);
	
	
	sistemasParticulas_.front()->addFuerza(G);
}


PeMundo::~PeMundo()
{
	for (auto w : sistemasParticulas_){
		delete w;
		w = nullptr;
	}
}


void PeMundo::update(float dT){

	for (auto w : solidosRigidos_){
		w->update(dT);
	}

	for (auto sP : sistemasParticulas_){
		for (auto p : sP->getParticulas()){
			p->update(dT);
		}
	}
}

void PeMundo::dibuja(){

	for (auto w : solidosRigidos_){
		w->dibuja();
	}
	
	for (auto sP : sistemasParticulas_){
		for (auto p : sP->getParticulas()){
			p->dibuja();
		}
	}
}

void PeMundo::step(){

	delta = glutGet(GLUT_ELAPSED_TIME) - lastUpdate;
	
	cont += delta / 1000;
	lastUpdate = glutGet(GLUT_ELAPSED_TIME);

	while (cont > 0.016){
	
		update(0.016);
		cont -= 0.016;
	}
	dibuja();
	
}