#ifndef PECOLLISIONMANAGER_H
#define PECOLLISIONMANAGER_H

#include "PeSolidoRigido.h"
#include <list>

class PeCollisionManager
{
public:

	PeCollisionManager(
		std::list<PeSolidoRigido*> solidosRigidos);

	~PeCollisionManager();

	std::list<PeSolidoRigido*> CollisionCheck();
	void ChangeList(std::list<PeSolidoRigido*> nueva);
	bool CollisionDetect(PeSolidoRigido* col1, PeSolidoRigido* col2);

private:

	std::list<PeSolidoRigido*> solidosRigidos_;
	std::list<PeSolidoRigido*> solidosColision_;
};

#endif