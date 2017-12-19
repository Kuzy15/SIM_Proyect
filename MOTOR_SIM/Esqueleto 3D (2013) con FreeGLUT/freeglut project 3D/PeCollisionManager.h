#ifndef PECOLLISIONMANAGER_H
#define PECOLLISIONMANAGER_H

#include "PeSolidoRigido.h"
#include <iostream>
#include <list>

class PeCollisionManager
{
public:

	PeCollisionManager(
		std::list<PeSolidoRigido*> solidosRigidos);

	~PeCollisionManager();

	std::list<PeSolidoRigido*> CollisionCheck();
	void ChangeList(std::list<PeSolidoRigido*> * nueva);
	bool CollisionDetect(PeSolidoRigido* col1, PeSolidoRigido* col2);
	bool CollisionDetectCubo(PeSolidoRigido* col1, PeSolidoRigido* col2);
	bool CollisionDetectEsfera(PeSolidoRigido* col1, PeSolidoRigido* col2);
	void collisionReactionsOMG(PeSolidoRigido* col1, PeSolidoRigido* col2);


	void ImprimeDebug() {
		std::cout<< numCol;
	}

private:
	int numCol = 0;
	std::list<PeSolidoRigido*> solidosRigidos_;
	std::list<PeSolidoRigido*> solidosColision_;
};

#endif