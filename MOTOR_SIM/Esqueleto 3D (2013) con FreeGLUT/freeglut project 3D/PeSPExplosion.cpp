#include "PeSPExplosion.h"
#include <iostream>
#include "PeMundo.h"

PeSPExplosion::PeSPExplosion(vec3 origen, int maxParticulas, float vida, float kvd) :PeSistemaParticulas(origen, maxParticulas, vida, kvd)

{
	vec3 g;
	g.x = 0; g.y = -9.8 ; g.z = 0;
	vec3 v;
	color3f c;
	c.a = 1; c.r = 1; c.b = 0; c.g = 0;

	for (int i = 0; i < maxParticulas_; i++){
		v = DameVectorAleatorio(dameRandom(10,-10));

		PeParticula* p = new PeParticula(0.1f, 1.0f, 5.0f, origen_, c, v,g);
		particulas_.push_back(p);
		
	}
}


PeSPExplosion::~PeSPExplosion()
{
	for (auto w : particulas_){
		delete w;
		w = nullptr;
	}
}

void PeSPExplosion::addFuerza(vec3 f){
	for (auto w : particulas_)
		w->AddFuerza(f);
}


void PeSPExplosion::update(GLfloat deltaTime){
	for (auto w : particulas_){
		w->update(deltaTime);

	}
}

/*bool PeSPExplosion::destroy(){
	for (auto w : particulas_){
		if (w->GetVida() > 0) return false;
	}
	return true;
}*/