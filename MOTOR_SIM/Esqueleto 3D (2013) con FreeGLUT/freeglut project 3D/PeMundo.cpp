#include "PeMundo.h"

#include "PeCubo.h"
#include "PeSPFuego.h"
#include "PeEsfera.h"
#include "PeCollisionManager.h"

PeMundo::PeMundo()
{
	origen.x = 0; origen.y = 2; origen.z = 0;
	origen2.x = 20; origen2.y = 0; origen2.z = 0;
	//descomentar esto y case i para colisiones de esferas
	e = nullptr;
	e1 = nullptr;

	/*e = new PeEsfera(2, origen, 1, 32, 32);
	e1 = new PeEsfera(2, origen2, 1, 32, 32);
	solidosRigidos_.emplace_back(e);
	solidosRigidos_.emplace_back(e1);*/


	// descomentar para poner fuego guapisimo
	origen.x = 0; origen.y = 2; origen.z = 0;
	origen2.x = 15; origen2.y = 0; origen2.z = 15;

	/*explo = new PeSPFuego(origen2, 5, 8.0f, 0, 'f'); // f -> fuego, h -> humo
	c = new PeCubo(1, origen2, 1, PeCubo::madera);
	c1 = new PeCubo(1, origen2, 1, PeCubo::madera);
	c2 = new PeCubo(1, origen2, 1, PeCubo::madera);
	solidosRigidos_.emplace_back(c);
	solidosRigidos_.emplace_back(c1);
	solidosRigidos_.emplace_back(c2);
	explotao = false;
	humillo = false;*/

	


	//colision = new PeCollisionManager(solidosRigidos_);
}


PeMundo::~PeMundo()
{
	for (auto w : sistemasParticulas_){
		delete w;
		w = nullptr;
	}
}


void PeMundo::HumoEnColision(PeSolidoRigido * c, PeSolidoRigido * c1) {
	vec3 humoPos;
	if (c->getRB()->getPos().x < c1->getRB()->getPos().x)
		humoPos.x = c->getRB()->getPos().x + ((c1->getRB()->getPos().x - c->getRB()->getPos().x) / 2);
	else
		humoPos.x = c1->getRB()->getPos().x + ((c->getRB()->getPos().x - c1->getRB()->getPos().x) / 2);

	if (c->getRB()->getPos().y < c1->getRB()->getPos().y)
		humoPos.y = c->getRB()->getPos().y + ((c1->getRB()->getPos().y - c->getRB()->getPos().y) / 2);
	else
		humoPos.y = c1->getRB()->getPos().y + ((c->getRB()->getPos().y - c1->getRB()->getPos().y) / 2);

	if (c->getRB()->getPos().z < c1->getRB()->getPos().z)
		humoPos.z = c->getRB()->getPos().z + ((c1->getRB()->getPos().z - c->getRB()->getPos().z) / 2);
	else
		humoPos.z = c1->getRB()->getPos().z + ((c->getRB()->getPos().z - c1->getRB()->getPos().z) / 2);

	humillo = true;
	humo = new PeSPFuego(humoPos, 5, 8.0f, 0, 'h');

}
void PeMundo::update(float dT){


	if (solidosRigidos_.size() > 1) {

		if (e != nullptr && e1 != nullptr){
			if (colision->CollisionDetectEsfera(e, e1)) {
				HumoEnColision(e, e1);
				colision->collisionReactionsOMG(e, e1);
			}
			/*if (colision->CollisionDetectCubo(c, c1)){
			colision->collisionReactionsOMG(c, c1);
			}*/
		}
	}
	for (auto w : solidosRigidos_){

		w->update(dT);
	}

	for (auto sP : sistemasParticulas_){
		for (auto p : sP->getParticulas()){
			p->update(dT);
		}
	}
	if (explotao) explo->update(dT);
	if (humillo) humo->update(dT);
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
	if (explotao) explo->dibuja();
	if (humillo) humo->dibuja();
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
	/*case 'r':
		explotao = true;
	break;*/
	case 'w':
		solidosRigidos_.push_front(new PeCubo(2, origen, 1, PeCubo::normal));
		a.x = 0; a.y = 1000; a.z = 400;
		fE.setDir(a);
		solidosRigidos_.front()->getRB()->addForce(fE);
		break;

	case 'a': 
		solidosRigidos_.push_front(new PeCubo(2, origen, 1, PeCubo::normal));
		a.x = 100; a.y = 0; a.z = 100;
		fE.setDir(a);
		
		t.y = 400; t.x = 500;

		solidosRigidos_.front()->getRB()->addTorque(t);
		break;

	case 's':  
		solidosRigidos_.push_front(new PeCubo(2, origen, 1, PeCubo::normal));
		a.x = 0; a.y = 800; a.z = 0;
		fE.setDir(a);
		solidosRigidos_.front()->getRB()->addForce(fE);
		break;

	case 'd': 
		solidosRigidos_.push_front(new PeCubo(2, origen, 1, PeCubo::normal));
		a.x = 0; a.y = 200; a.z = -700;
		t.y = 400; t.x = 500;
		solidosRigidos_.front()->getRB()->addTorque(t);
		fE.setDir(a);
		solidosRigidos_.front()->getRB()->addForce(fE);
		break;
	/*case 'i':
		a.x = 1000; a.y = 0; a.z = 0;
		e->getRB()->addForce(a);
		break;*/

	default:
		break;
	}


}