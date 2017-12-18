#include "PeCollisionManager.h"


PeCollisionManager::PeCollisionManager(
	std::list<PeSolidoRigido*> solidosRigidos)
{
	solidosRigidos_ = solidosRigidos;
	solidosColision_ = solidosRigidos;
}

PeCollisionManager::~PeCollisionManager()
{
}
void PeCollisionManager::ChangeList(std::list<PeSolidoRigido*> * nueva)
{

	// cada vez que creemos un objeto en PeMundo habr�a que llamar a la constructora,
	// para pasarle la nueva lista
	solidosRigidos_ = *nueva;
	solidosColision_ = *nueva;
	// habr�a que ver tambi�n si se colision� antes, ya que las dos listas pueden ser diferentes
}
bool PeCollisionManager::CollisionDetect(PeSolidoRigido* col1, PeSolidoRigido* col2) {
	//se comprueba si hay colision entre col1 y col2
	//if (col1 == nullptr || col2 == nullptr) return false;
	//float t = (float)col1->getRB()->getPos().x;
	return std::sqrt(std::pow((col1->getRB()->getPos().x - col2->getRB()->getPos().x), 2) +
		std::pow((col1->getRB()->getPos().y - col2->getRB()->getPos().y), 2) +
		std::pow((col1->getRB()->getPos().z - col2->getRB()->getPos().z), 2)) < col1->getRB()->getTam() + col2->getRB()->getTam();

}

bool PeCollisionManager::CollisionDetectCubo(PeSolidoRigido* col1, PeSolidoRigido* col2) {
	float x1, y1, z1, x2, y2, z2, tam1, tam2;
	tam1 = col1->getRB()->getTam();
	tam2 = col2->getRB()->getTam();

	x1 = col1->getRB()->getPos().x - tam1 / 2;
	y1 = col1->getRB()->getPos().y - tam1 / 2;
	z1 = col1->getRB()->getPos().z - tam1 / 2;
	x2 = col2->getRB()->getPos().x - tam2 / 2;
	y2 = col2->getRB()->getPos().y - tam2 / 2;
	z2 = col2->getRB()->getPos().z - tam2 / 2;

	return (x1 + tam1 >= x2 && x1 <= x2 || y1 + tam1 >= y2 && y1 <= y2 || z1 + tam1 >= z2 && z1 < z2);

}

bool PeCollisionManager::CollisionDetectEsfera(PeSolidoRigido* col1, PeSolidoRigido* col2) {

	
	float x1, y1, z1, x2, y2, z2;
	
	float r1, r2;

	r1 = col1->getRB()->getTam();
	r2 = col2->getRB()->getTam();

	x1 = col1->getRB()->getPos().x;
	y1 = col1->getRB()->getPos().y;
	z1 = col1->getRB()->getPos().z;
	x2 = col2->getRB()->getPos().x;
	y2 = col2->getRB()->getPos().y;
	z2 = col2->getRB()->getPos().z;

	float distance;

	float aux = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2);

	distance = std::sqrt(aux);

	std::cout << "ay CHIGUAGUAAAAAAAAAAAAA!";

	return (distance <= r1 + r2);
}


void PeCollisionManager::collisionReactionsOMG(PeSolidoRigido* col1, PeSolidoRigido* col2) {

}




//el metodo collisionCheck nos devuelve una lista de solidos en la cual LA POSICION del puntero en dicha lista 
//nos indica el primer objeto que colisiona , que esta en la misma posicion en la lista solidosRigidos_,
//y el PUNTERO situado en dicha posicion nos indica el segundo objeto a colisionar.
//Objeto 1 = POSICION DE SolidosColision_ en SolidosRigidos_. Objeto 2 = PUNTERO dentro de la posicion en SolidosColision_

std::list<PeSolidoRigido*> PeCollisionManager::CollisionCheck() {
	std::list<PeSolidoRigido*>::iterator it1 = solidosRigidos_.begin();
	std::list<PeSolidoRigido*>::iterator it2 = solidosRigidos_.begin();

	std::list<PeSolidoRigido*>::iterator it3 = solidosColision_.begin();
	std::list<PeSolidoRigido*>::iterator it4 = solidosColision_.begin();
	if (solidosRigidos_.size() != 1) {
		//recorremos la lista de solidos "dos veces" con coste !N.
		for (int i = 0; i < solidosRigidos_.size() -1; i++) {
			it1 = solidosRigidos_.begin();
			it2 = solidosRigidos_.begin();
			std::advance(it1, i);
			for (int l = i + 1; l < solidosRigidos_.size(); l++) {
				it3 = solidosColision_.begin();
				it4 = solidosColision_.begin();
				std::advance(it2, l);
				//if (&it1 != nullptr && &it2 != nullptr){
					if (CollisionDetect(*it1, *it2)) {
						numCol++;
						std::advance(it3, i);
						std::advance(it4, l);
						*it3 = *it4;
					}		
			//}
				else { std::advance(it3, i); *it3 = nullptr; } //no colisiona con nada
			}			
		}
	}
	return solidosColision_;

}

