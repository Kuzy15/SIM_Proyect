#include "PeMundo.h"
#include "PeSPHumo.h"



PeMundo::PeMundo()
{
	
	vec3 origen;
	origen.x = 1; origen.y = 0; origen.z = 1;
	explo = new PeSPExplosion(origen,1500,100.0, 0);
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

void PeMundo::simula(){

	/*for (auto w : sistemasParticulas_){
		for (auto p : w->getParticulas()){
			w->SimulaPasoParticula(p,);
			}
	}*/
}

void PeMundo::dibuja(){
	GLfloat delta = glutGet(GLUT_ELAPSED_TIME);

	for (auto w : sistemasParticulas_){
		for (auto p : w->getParticulas()){
			p->dibuja();

			if (lastFrame + frec <= delta)
			{
				explo->SimulaPasoParticula(p, delta);
			}
		}
	}
	

}