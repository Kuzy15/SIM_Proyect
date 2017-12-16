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
void PeCollisionManager::ChangeList(std::list<PeSolidoRigido*> nueva)
{

	// cada vez que creemos un objeto en PeMundo habría que llamar a la constructora,
	// para pasarle la nueva lista
	solidosRigidos_ = nueva;
	solidosColision_ = nueva;
	// habría que ver también si se colisionó antes, ya que las dos listas pueden ser diferentes
}
bool PeCollisionManager::CollisionDetect(PeSolidoRigido* col1, PeSolidoRigido* col2) {
	//se comprueba si hay colision entre col1 y col2
	float t = (float)col1->getRB()->getPos().x;

	return std::sqrt(std::pow((col1->getRB()->getPos().x - col2->getRB()->getPos().x), 2) +
		std::pow((col1->getRB()->getPos().y - col2->getRB()->getPos().y), 2) +
		std::pow((col1->getRB()->getPos().z - col2->getRB()->getPos().z), 2)) < col1->getRB()->getTam() + col2->getRB()->getTam();

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
	if (!solidosRigidos_.size() == 1) {
		//recorremos la lista de solidos "dos veces" con coste !N.
		for (int i = 0; i < solidosRigidos_.size() - 1; i++) {
			std::advance(it1, i);
			for (int l = i + 1; i < solidosRigidos_.size(); l++) {
				std::advance(it2, l);
				if (CollisionDetect(*it1, *it2)) {
					std::advance(it3, i);
					std::advance(it4, l);
					*it3 = *it4;
				}
				else *it3 = nullptr; //no colisiona con nada
			}
		}
	}
	return solidosColision_;

}

