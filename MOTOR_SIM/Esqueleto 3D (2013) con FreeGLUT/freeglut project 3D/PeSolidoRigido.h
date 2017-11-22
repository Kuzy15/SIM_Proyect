#ifndef PESOLIDORIGIDO_H
#define PESOLIDORIGIDO_H

#include "ObjetosCuadricos.h"
#include "PeRigidBody.h"

class PeSolidoRigido
{
protected:
	ObjetoCuadrico* ob_;
	PeRigidBody* rb_;
	
public:
	PeSolidoRigido();
	~PeSolidoRigido();

	void update(const float &dT);
	void dibuja();
	void setGravedad(bool g);


	inline PeRigidBody* getRB(){ return rb_; }

	struct color3f {
		GLfloat r;
		GLfloat g;
		GLfloat b;
		GLfloat a;
	};

	color3f _color;



};
#endif
