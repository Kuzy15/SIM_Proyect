#include "PeSPFuego.h"


PeSPFuego::PeSPFuego(vec3 origen, int maxParticulas, float vida, float kvd) :PeSistemaParticulas(origen, maxParticulas, vida, kvd)
{

	g.x = 0; g.y = 0.5; g.z = 0;
	c.a = 1; c.r = 1; c.b = 0; c.g = 0;

	for (int i = 0; i < maxParticulas_; i++){
		// fuego de angel
		/*v = DameVectorAleatorio(dameRandom(2, -2));

		PeParticula* p = new PeParticula(0.1f, 1.0f, 5.0f, origen_, c, v, g);
		particulas_.push_back(p);*/

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
	// fuego de alex
	
	for (size_t i = 0; i < 20; i++)
	{
		v = DameVectorAleatorio(dameRandom(1, -1));
		PeParticula* p = new PeParticula(0.1f, 1.0f, 5.0f, origen_, c, v, g);
		particulas_.push_back(p);
	}
	

	for (auto w : particulas_){
		w->update(deltaTime);	
	}
}