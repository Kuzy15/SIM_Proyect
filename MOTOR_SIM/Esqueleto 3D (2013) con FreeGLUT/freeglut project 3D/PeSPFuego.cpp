#include "PeSPFuego.h"


PeSPFuego::PeSPFuego(vec3 origen, int maxParticulas, float vida, float kvd, char t)
	:PeSistemaParticulas(origen, maxParticulas, vida, kvd)
{


	_t = t;
	if (t == 'f') {
		numPart = 10; //por frame
		c.a = 1; c.r = 1; c.b = 0; c.g = 0;
		g.x = 0; g.y = 0.6; g.z = 0;
	}
	else {
		numPart = 15; //por frame
		c.a = 0; c.r = 0.6; c.b = 0.6; c.g = 0.6;
		g.x = 0; g.y = 0.8; g.z = 0;
	}
	x = origen.x;
	y = origen.y;
	z = origen.z;
}


PeSPFuego::~PeSPFuego()
{
	for (auto w : particulas_) {
		delete w;
		w = nullptr;
	}
}

void PeSPFuego::addFuerza(vec3 f) {
	for (auto w : particulas_)
		w->AddFuerza(f);
}


void PeSPFuego::update(GLfloat deltaTime) {
	// fuego de alex

	for (size_t i = 0; i < numPart; i++)
	{
		if (_t == 'f') v = DameVectorAleatorio(dameRandom(0.5, -0.5));
		else v = DameVectorAleatorio(dameRandom(1, -1));
		origen_.z = dameRandom(2+z, -2+z);
		origen_.y = dameRandom(2.1+y, -0.5+y);
		origen_.x = dameRandom(1+x, -1+x);
		if (origen_.y > 0) {
			if (dameRandom(1, 0) < 0.5) {
				//origen_.z = -dameRandom(2 - origen_.y +z, z);
				//origen_.x = -dameRandom(2 - origen_.y+x, x);

			}
			else {
				//origen_.z = dameRandom(2 - origen_.y+z, z);
				//origen_.x = dameRandom(2 - origen_.y+x, x);

			}


		}

		PeParticula* p = new PeParticula(0.1f, 1.0f, 5.0f, origen_, c, v, g, _t);
		particulas_.push_back(p);
	}


	for (auto w : particulas_) {
		w->update(deltaTime);
	}
}