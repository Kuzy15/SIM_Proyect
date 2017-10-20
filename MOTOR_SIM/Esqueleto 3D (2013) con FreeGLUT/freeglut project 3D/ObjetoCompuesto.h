#ifndef OBJETO_COMPUESTO_H
#define OBJETO_COMPUESTO_H

#include "Objeto3D.h"

class ObjetoCompuesto :
	public Objeto3D
{
protected:
	int numHijos;
	std::vector<Objeto3D*> hijos;


public:

	ObjetoCompuesto();
	virtual ~ObjetoCompuesto();
	virtual void dibuja();

	void addObjeto(Objeto3D* newObj);
};

#endif