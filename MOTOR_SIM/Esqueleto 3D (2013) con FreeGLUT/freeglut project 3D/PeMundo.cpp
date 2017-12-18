#include "PeMundo.h"

#include "PeCubo.h"
#include "PeSPFuego.h"

PeMundo::PeMundo()
{
	origen.x = 0; origen.y = -0.01; origen.z = 0;
	
	//explo = new PeSPFuego(origen, 5000, 8.0f, 0);
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
	//explo->update(dT);
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
	//explo->dibuja();
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

void PeMundo::input(unsigned char key){

	switch (key) {
	case 'w':
		solidosRigidos_.push_front(new PeCubo(2, origen, 1));
		 a.x = 0; a.y = 200; a.z = -50;
		fE.setDir(a);
		
		solidosRigidos_.front()->getRB()->applyForce(fE);
		break;
	case 'a': 
		solidosRigidos_.push_front(new PeCubo(2, origen, 1));
		a.x = -100; a.y = 0; a.z = 0;
		fE.setDir(a);
		
		//solidosRigidos_.front()->getRB()->addForce(fE);
		solidosRigidos_.front()->getRB()->setRozamiento(true,0.2);
		break;
	case 's':  
		solidosRigidos_.push_front(new PeCubo(2, origen, 1));
		a.x = 0; a.y = 0; a.z = 100;
		fE.setDir(a);

		solidosRigidos_.front()->getRB()->applyForce(fE);
		solidosRigidos_.front()->getRB()->setRozamiento(true, 0.4);
		break;
	case 'd': 
		solidosRigidos_.push_front(new PeCubo(2, origen, 1));
		a.x = 50; a.y = 200; a.z = 0;
		fE.setDir(a);
		
		solidosRigidos_.front()->getRB()->applyForce(fE);
		break;
	default:
		
		break;
	}


}