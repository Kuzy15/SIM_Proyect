#include "PeSPFuego.h"


PeSPFuego::PeSPFuego(vec3 origen, int maxParticulas, float vida, float kvd) :PeSistemaParticulas(origen, maxParticulas, vida, kvd)
{

	vec3 g;
	g.x = 0; g.y = 5; g.z = 0;
	vec3 v;
	color3f c;
	c.a = 1; c.r = 1; c.b = 0; c.g = 0;

	for (int i = 0; i < maxParticulas_; i++){
		v = DameVectorAleatorio(dameRandom(2, -2));

		PeParticula* p = new PeParticula(0.1f, 1.0f, 5.0f, origen_, c, v, g);
		particulas_.push_back(p);

	}
}


PeSPFuego::~PeSPFuego()
{
	for (auto w : particulas_){
		delete w;
		w = nullptr;
	}
}

void PeSPFuego::addFuerza(vec3 f){
	for (auto w : particulas_)
		w->AddFuerza(f);
}


void PeSPFuego::update(GLfloat deltaTime){

	
	for (auto w : particulas_){
		w->update(deltaTime);
	
	}
}