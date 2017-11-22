#ifndef PERIGIDBODY_H
#define PERIGIDBODY_H



#include "PeFuerza.h"

class PeRigidBody
{
public:
	PeRigidBody(vec3 origen, float mass);
	virtual ~PeRigidBody();
	void update(float dT);
	void addForce(PeFuerza nF);
	void applyForce(PeFuerza impulse);
	void setRozamiento(bool r, float cR);

	inline const vec3 &getPos(){ return _position; };

	vec3 FG_;
private:
	float _tam;
	float _mass;
	float coefRoz;
	vec3 _position;
	vec3 _vel;
	vec3 _angularMomemtum;
	vec3 _angularVel;
	vec3 _force;
	vec3 _torque;
	vec3 _aceleracion;
	vec3 _impulse;
	vec3 forceRoz;
	float _fRoz;
	bool hasRozamiento;
	
	
};

#endif