#include "PeMundo.h"

#include "PeCubo.h"
#include "PeSPFuego.h"
#include "PeEsfera.h"
#include "PeCollisionManager.h"

PeMundo::PeMundo()
{
	origen.x = 0; origen.y = 2; origen.z = 0;
	origen2.x = 5; origen2.y = 0; origen2.z = 0;

	//explo = new PeSPFuego(origen, 5000, 8.0f, 0);
	//descomentar esto y case i para colisiones de esferas
	/*c = new PeEsfera(2, origen, 1, 32, 32);
	c1 = new PeEsfera(2, origen2, 1, 32, 32);
	solidosRigidos_.emplace_back(c);
	solidosRigidos_.emplace_back(c1);*/


	//colision = new PeCollisionManager(solidosRigidos_);
}


PeMundo::~PeMundo()
{
	for (auto w : sistemasParticulas_){
		delete w;
		w = nullptr;
	}
}


void PeMundo::update(float dT){


	if (solidosRigidos_.size() > 1) {
		/*if (colision->CollisionDetectEsfera(c, c1)){
			colision->collisionReactionsOMG(c, c1);
		}*/
	}
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
	vec3 t = vec3Zero();
	switch (key) {
	case 'w':
		solidosRigidos_.push_front(new PeCubo(2, origen, 1));
		a.x = 0; a.y = 1000; a.z = -50;
		fE.setDir(a);
		solidosRigidos_.front()->getRB()->addForce(fE);
		break;

	case 'a': 
		solidosRigidos_.push_front(new PeCubo(2, origen, 1));
		a.x = 100; a.y = 0; a.z = 100;
		fE.setDir(a);
		
		t.y = 50; t.x = 150;

		solidosRigidos_.front()->getRB()->addTorque(t);
		
		solidosRigidos_.front()->getRB()->addForce(fE);
		solidosRigidos_.front()->getRB()->setRozamiento(true,0.2);
		break;

	case 's':  
		solidosRigidos_.push_front(new PeCubo(2, origen, 1));
		a.x = 0; a.y = 0; a.z = 100;
		fE.setDir(a);
		solidosRigidos_.front()->getRB()->setRozamiento(true, 0.4);
		break;

	case 'd': 
		solidosRigidos_.push_front(new PeCubo(2, origen, 1));
		a.x = 50; a.y = 200; a.z = 0;
		fE.setDir(a);
		break;
	/*case 'i':
		a.x = 1000; a.y = 0; a.z = 0;
		c->getRB()->addForce(a);
		break;*/

	default:
		break;
	}


}