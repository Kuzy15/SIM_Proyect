#ifndef OBJETOCUADRICO_H
#define OBJETOCUADRICO_H

#include "Objeto3D.h"

class ObjetoCuadrico :
	public Objeto3D
{
public:

	ObjetoCuadrico();
		
	

	virtual ~ObjetoCuadrico();

protected:
	GLUquadricObj* obj;
};
#endif
