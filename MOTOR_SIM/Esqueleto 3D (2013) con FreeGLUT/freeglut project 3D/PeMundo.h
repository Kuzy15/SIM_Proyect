#ifndef PEMUNDO_H
#define PEMUNDO_H


#include "PeSistemaParticulas.h"
#include "PeSolidoRigido.h"
#include "PeCubo.h"
#include "PeEsfera.h"
#include "PeCollisionManager.h"


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
	PeSistemaParticulas* humo;
	vec3 origen;
	vec3 origen2;
	vec3 origen3;

	vec3 a;

	GLfloat delta;
	GLfloat lastUpdate = glutGet(GLUT_ELAPSED_TIME);
	GLfloat cont = 0;

	PeFuerza fE;
	/*aBodies;*/

	PeCubo* c = nullptr;
	PeCubo* c1 = nullptr;
	PeCubo* c2 = nullptr;

	PeEsfera* e = nullptr;
	PeEsfera* e1 = nullptr;

	bool explotao = false;
	bool humillo = false;
	PeCollisionManager* colision = nullptr;

	bool b = false;

public:
	PeMundo();
	~PeMundo();

	
	const vec3 getTam(){ return tam_; };

	const vec3 getGravedad(){ return gravedad_; };

	inline list<PeSistemaParticulas*> getSistemasParticulas(){ return sistemasParticulas_; };

	inline list<PeFuerza*> getFuerzas(){ return fuerzas_; };

	inline void setGravedad(vec3 g){ gravedad_ = g; };

	void input(unsigned char key);

	void update(float dT);

	void dibuja();

	void step();


	void HumoEnColision(PeSolidoRigido * c, PeSolidoRigido * c1);

};

#endif