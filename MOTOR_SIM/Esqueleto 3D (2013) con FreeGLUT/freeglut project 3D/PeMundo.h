#ifndef PEMUNDO_H
#define PEMUNDO_H

#include "PeSistemaParticulas.h"


class PeMundo
{
private:
	vec3 tam_; //Longitud en los tres ejes del tamaño del mundo
	vec3 gravedad_; //Vector de la gravedad.
	list<PeSistemaParticulas*> sistemasParticulas_; //Arrays de sistemas de partículas

public:
	PeMundo();
	~PeMundo();

	const vec3 getTam(){ return tam_; };

	const vec3 getGravedad(){ return gravedad_; };

	void setGravedad();

	void dibuja();

};

#endif