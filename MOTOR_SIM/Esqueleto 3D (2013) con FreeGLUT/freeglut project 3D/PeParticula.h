#ifndef PEPARTICULA_H
#define PEPARTICULA_H
//OpenGL siempre antes que el ccVector
#include "ObjetosCuadricos.h"
#include "ccVector.h"

class PeParticula
{
private: 

	float masa_;
	vec3 pos_;
	vec3 vel_;
	vec3 fuerzas_;
	float vidaRes_;
	float tam_;
	vec3 color_;

	Objeto3D* render_;

public:
	PeParticula(int tam, float masa, vec3 pos, vec3 color);
	virtual ~PeParticula();

	void dibuja();
};

#endif
