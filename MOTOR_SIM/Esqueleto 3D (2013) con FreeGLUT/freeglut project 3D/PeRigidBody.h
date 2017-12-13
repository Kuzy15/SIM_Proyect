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
	//Variables constantes
	float  _mass;
	mat3x3 _Ibody;
	mat3x3 _Ibodyinv;
	//Variables de estado
	vec3 _position;
	mat3x3 _R;
	vec3 _P;
	vec3 _L;
	//Variables derivadas (auxiliares)
	mat3x3 _Iinv; 
	vec3 _vel;
	vec3 _omega;
	//Variables computadas
	vec3 _force;
	vec3 _torque;

	float _tam;
	float coefRoz;
	vec3 _aceleracion;
	vec3 _impulse;
	vec3 forceRoz;
	float _fRoz;
	bool hasRozamiento;
	
	
};

#endif