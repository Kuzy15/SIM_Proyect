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

	inline quat  normalize() {
		vec4 vecAux;
		vecAux.w = _Q.w; vecAux.x = _Q.x;
		vecAux.y = _Q.y; vecAux.z = _Q.z;
		float length = vec4Length(vecAux);
		if (length <= 0)
			return quatIdentity();
		float oneOverLength = 1 / length;
		vec4 vecNormalized = vec4Multiply(vecAux, oneOverLength);
		quat quatNormalized;
		quatNormalized.w = vecNormalized.w; quatNormalized.x = vecNormalized.x;
		quatNormalized.y = vecNormalized.y; quatNormalized.z = vecNormalized.z;
		return quatNormalized;
	
	}

	inline void quaternionToMatrix(const quat &q) {
		_R[0][0] = 1 - (2 * pow(q.y, 2)) - (2 * pow(q.z, 2));
		_R[0][1] = (2 * q.x *  q.y) + (2 * q.w * q.z);
		_R[0][2] = (2 * q.x *  q.z) - (2 * q.w * q.y);
		_R[1][0] = (2 * q.x *  q.y) - (2 * q.w * q.z);
		_R[1][1] = 1 - (2 * pow(q.x, 2)) - (2 * pow(q.z, 2));
		_R[1][2] = (2 * q.y *  q.z) + (2 * q.w * q.x);
		_R[2][0] = (2 * q.x *  q.z) + (2 * q.w * q.y);
		_R[2][1] = (2 * q.y *  q.z) - (2 * q.w * q.x);
		_R[2][2] = 1 - (2 * pow(q.x, 2)) - (2 * pow(q.y, 2));
		
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
	float r[16];//Aux
	quat _Q;
	vec3 _P;
	vec3 _L;
	mat4x4 _M;
	//Variables derivadas (auxiliares)
	mat3x3 _Iinv; 
	mat3x3 _R;
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