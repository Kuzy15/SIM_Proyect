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
	void addTorque(PeFuerza nF);
	void applyForce(PeFuerza impulse);
	void setRozamiento(bool r, float cR);
	void computeForces();
	inline const vec3 &getPos(){ return _position; };
	inline float* getR()
	{ 
		
		r[0] = _R[0][0]; r[4] = _R[0][1]; r[8] = _R[0][2]; r[12] = 0;
		r[1] = _R[1][0]; r[5] = _R[1][1]; r[9] = _R[1][2]; r[13] = 0;
		r[2] = _R[2][0]; r[6] = _R[2][1]; r[10] = _R[2][2]; r[14] = 0;
		r[3] = 0; r[7] = 0; r[11] = 0; r[15] = 1;
		
		return r; }

	vec3 FG_;
private:
	//Variables constantes
	float  _mass;
	mat3x3 _Ibody;
	mat3x3 _Ibodyinv;
	//Variables de estado
	vec3 _position;
	mat3x3 _R;
	float r[16];//Aux
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