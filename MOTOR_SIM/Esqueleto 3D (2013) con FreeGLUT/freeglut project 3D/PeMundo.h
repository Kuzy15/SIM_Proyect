#ifndef PEMUNDO_H
#define PEMUNDO_H


#include "PeSistemaParticulas.h"
#include "PeFuerza.h"
#include "PeSolidoRigido.h"


class PeMundo
{
private:
	vec3 tam_; //Longitud en los tres ejes del tamaño del mundo
	vec3 gravedad_; //Vector de la gravedad.
	list<PeSistemaParticulas*> sistemasParticulas_; //Arrays de sistemas de partículas
	list<PeFuerza*> fuerzas_;
	list<PeSolidoRigido*> solidosRigidos_;
	double lastFrame = 0;
	GLfloat frec = 10;
	PeSistemaParticulas* explo;
	vec3 origen;

	GLfloat delta;
	GLfloat lastUpdate = glutGet(GLUT_ELAPSED_TIME);
	GLfloat cont = 0;
	/*aBodies;*/

public:
	PeMundo();
	~PeMundo();

	
	const vec3 getTam(){ return tam_; };

	const vec3 getGravedad(){ return gravedad_; };

	inline list<PeSistemaParticulas*> getSistemasParticulas(){ return sistemasParticulas_; };

	inline list<PeFuerza*> getFuerzas(){ return fuerzas_; };

	inline void setGravedad(vec3 g){ gravedad_ = g; };

	void update(float dT);

	void dibuja();

	void step();

	

};

#endif