#ifndef PERIGIDBODY_H
#define PERIGIDBODY_H



#include "PeFuerza.h"

class PeRigidBody
{
public:
	PeRigidBody(float tam, vec3 origen, float mass);
	virtual ~PeRigidBody();
	void update(float dT);
	void addForce(PeFuerza nF);
	void addTorque(PeFuerza nF);
	void setRozamiento(bool r, float cR);
	void computeForces();
	inline const vec3 &getPos(){ return _position; };
	inline void getR4x4(mat4x4 &aux)
	{ 
		aux[0][0] = _R[0][0]; aux[0][1] = _R[0][1]; aux[0][2] = _R[0][2]; aux[0][3] = 0;
		aux[1][0] = _R[1][0]; aux[1][1] = _R[1][1]; aux[1][2] = _R[1][2]; aux[1][3] = 0;
		aux[2][0] = _R[2][0]; aux[2][1] = _R[2][1]; aux[2][2] = _R[2][2]; aux[2][3] = 0;
		aux[3][0] = 0;        aux[3][1] = 0;        aux[3][2] = 0;        aux[3][3] = 1;
		
	}

	inline void normalize() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (_R[i][j] > 1.0f) _R[i][j] = 1.0f;
				else if (_R[i][j] < -1.0f) _R[i][j] = -1.0f;
			}
		}
	
	
	}

	inline const mat4x4 &getMfin() { return _M; }

	inline const float getTam() { return _tam; };

	inline const vec3 getVel(){ return _vel; };

	inline const float getMass(){ return _mass; };

	void setP(vec3 p){ _P = p; };

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
	mat4x4 _M;
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
	vec3 forceAc;
	vec3 torqueAc;
	float _fRoz;
	bool hasRozamiento;
	
	
};

#endif