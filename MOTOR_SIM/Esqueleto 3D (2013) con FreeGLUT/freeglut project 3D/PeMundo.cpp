#include "PeMundo.h"


PeMundo::PeMundo()
{
	
	
	origen.x = 0; origen.y = 0; origen.z = 0;
	//explo = new PeSPExplosion(origen, 5000, 100.0, 0);
	explo = new PeSPFuego(origen, 5000, 10.0f, 0);
	sistemasParticulas_.push_back(explo);
	
	
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
	/*if (explo->destroy()){
		explo = new PeSPExplosion(origen, 5000, 100.0, 0);
	}*/
	explo->update(delta);

}