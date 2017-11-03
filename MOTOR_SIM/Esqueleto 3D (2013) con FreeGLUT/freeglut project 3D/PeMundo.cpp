#include "PeMundo.h"


PeMundo::PeMundo()
{
	
	
	origen.x = 5; origen.y = 5; origen.z = 0;
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


	//glutGet(glut_)

	delta = glutGet(GLUT_ELAPSED_TIME);
	explo->dibuja();

	/*if (explo->destroy()){
		explo = new PeSPExplosion(origen, 5000, 100.0, 0);
	}*/
	explo->update(delta);

	
	/*if (lastFrame + frec <= delta)
	{
		
	//}
	/*for (auto w : sistemasParticulas_){
		for (auto p : w->getParticulas()){
			p->dibuja();

			if (lastFrame + frec <= delta)
			{
				explo->update(delta);
			}
		}
	}
	*/

}