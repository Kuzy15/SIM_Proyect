#ifndef PESOLIDORIGIDO_H
#define PESOLIDORIGIDO_H

#include "ObjetosCuadricos.h"
#include "PeRigidBody.h"
class PeSolidoRigido
{
private:
	PeRigidBody* rb_;
	ObjetoCuadrico* ob_;
public:
	PeSolidoRigido();
	~PeSolidoRigido();

	void update(const float &dT);
	void dibuja();

};
#endif
