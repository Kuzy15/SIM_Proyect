#ifndef PERIGIDBODY_H
#define PERIGIDBODY_H

#include "ObjetosCuadricos.h"
#include "ccVector.h"
#include "PeFuerza.h"

class PeRigidBody
{
public:
	PeRigidBody(vec3 origen, GLfloat tam, GLfloat mass);
	virtual ~PeRigidBody();
	void update(float dT);
	void addForce(PeFuerza nF);
	void applyForce(PeFuerza impulse);
	void dibuja();
private:
	float _tam;
	float _mass;
	vec3 _position;
	vec3 _vel;
	vec3 _angularMomemtum;
	vec3 _angularVel;
	vec3 _force;
	vec3 _torque;
	vec3 _aceleracion;
	vec3 _impulse;

	GLfloat _sec;
	struct color3f {
		GLfloat r;
		GLfloat g;
		GLfloat b;
		GLfloat a;
	};
	color3f _color;
	vec3 FG;
	
};

#endif