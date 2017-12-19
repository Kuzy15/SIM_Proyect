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

	// cada vez que creemos un objeto en PeMundo habría que llamar a la constructora,
	// para pasarle la nueva lista
	solidosRigidos_ = *nueva;
	solidosColision_ = *nueva;
	// habría que ver también si se colisionó antes, ya que las dos listas pueden ser diferentes
}
bool PeCollisionManager::CollisionDetect(PeSolidoRigido* col1, PeSolidoRigido* col2) {
	//se comprueba si hay colision entre col1 y col2
	//if (col1 == nullptr || col2 == nullptr) return false;
	//float t = (float)col1->getRB()->getPos().x;
	//return std::sqrt(std::pow((col1->getRB()->getPos().x - col2->getRB()->getPos().x), 2) +
	/*	std::pow((col1->getRB()->getPos().y - col2->getRB()->getPos().y), 2) +
		std::pow((col1->getRB()->getPos().z - col2->getRB()->getPos().z), 2)) < col1->getRB()->getTam() + col2->getRB()->getTam();*/
	return true;

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

	

	return (x1 + tam1 >= x2 && x1 <= x2 && y1 + tam1 >= y2 && y1 <= y2 && z1 + tam1 >= z2 && z1 < z2);

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

	return (distance <= r1 + r2);
}


void PeCollisionManager::collisionReactionsOMG(PeSolidoRigido* col1, PeSolidoRigido* col2) {
	float b = col1->getRB()->getPos().y - col2->getRB()->getPos().y;
	float sina = b / (col1->getRB()->getTam() + col2->getRB()->getTam());
	float degrees1 = std::asin(sina);
	float cosa = std::cos(degrees1);

	int degrees2 = 90 - ((degrees1 * 180) / 3.141592654);
	float degrees2Radian = degrees2 * 3.141592654 / 180;
	float sinD2 = std::sin(degrees2Radian);
	float cosD2 = std::cos(degrees2Radian);



	vec3 v2 = col1->getRB()->getVel();
	v2 = vec3Divide(v2, 1.5);

	vec3 v1 = col1->getRB()->getVel();
	v1 = vec3Divide(v1, 1.5);

	float vModulo = std::sqrt(std::pow(v2.x, 2) + std::pow(v2.y, 2) + std::pow(v2.z, 2));

	v2.x = vModulo * cosa;
	v2.y = -vModulo * sina;

	v1.x = vModulo * cosD2;
	v1.y = vModulo * sinD2;

	vec3 mL2 = vec3Multiply(v2, col2->getRB()->getMass());
	vec3 mL1 = vec3Multiply(v1, col1->getRB()->getMass());

	col2->getRB()->setP(mL2);
	col1->getRB()->setP(mL1);


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

