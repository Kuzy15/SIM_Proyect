#include "PeMundo.h"


PeMundo::PeMundo()
{
	
	
	origen.x = 0; origen.y = 0; origen.z = 0;
	//explo = new PeSPExplosion(origen, 5000, 100.0, 0);
	explo = new PeSPFuego(origen, 5000, 8.0f, 0);
	sistemasParticulas_.push_back(explo);
	

	rb = new PeRigidBody(origen, 2, 2);
	
	vec3 g; g.x = 0; g.y = 0; g.z = 0;
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

void PeMundo::dibuja(){



	delta = glutGet(GLUT_ELAPSED_TIME);
	explo->dibuja();
	
	explo->update(delta);
	//rb->dibuja();
	//rb->update(delta);
}