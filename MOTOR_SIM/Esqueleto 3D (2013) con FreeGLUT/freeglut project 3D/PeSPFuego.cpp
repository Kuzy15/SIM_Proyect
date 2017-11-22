#include "PeSPFuego.h"

#include <iostream>
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
	
	for (size_t i = 0; i < 30; i++)
	{
		v = DameVectorAleatorio(dameRandom(0.51, -0.51));
		origen_.z = dameRandom(2, -2);
		origen_.y = dameRandom(2.1, -0.5);
		origen_.x = dameRandom(1, -1);
		if (origen_.y > 0){
			if (dameRandom(1, 0) < 0.5){
				origen_.z = -dameRandom(2 - origen_.y, 0);
				origen_.x = -dameRandom(2 - origen_.y, 0);
			}
			else {
				origen_.z = dameRandom(2 - origen_.y, 0);
				origen_.x = dameRandom(2 - origen_.y, 0);
			}
			
		}
		
		PeParticula* p = new PeParticula(0.1f, 1.0f, 4.0f, origen_, c, v, g);
		particulas_.push_back(p);
	}
	

	for (auto w : particulas_){
		w->update(deltaTime);	
	}
}