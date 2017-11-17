#ifndef PERIGIDBODY_H
#define PERIGIDBODY_H

#include "ccVector.h"
#include "PeFuerza.h"

class PeRigidBody
{
public:
	PeRigidBody();
	virtual ~PeRigidBody();
	void update(float dT);
	void addForce(PeFuerza nF);
	void applyForce(PeFuerza impulse);
private:

	float _mass;
	vec3 _position;
	vec3 _vel;
	vec3 _angularMomemtum;
	vec3 _angularVel;
	vec3 _force;
	vec3 _torque;
	vec3 _acceleracion;
	vec3 _impulse;
	const vec3 FG = vec3Multiply(G, _mass);
	
};

#endif