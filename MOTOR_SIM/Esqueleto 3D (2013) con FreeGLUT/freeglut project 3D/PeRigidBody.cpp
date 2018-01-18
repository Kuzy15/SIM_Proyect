#include "PeRigidBody.h"
#include <iostream>




PeRigidBody::PeRigidBody(float tam, vec3 origen, float mass)
{

	_tam = tam;

	mat3x3Identity(_Ibody);
	//Tensor de inercia. BUSCAR TAM
	_Ibody[0][0] = ((mass / 12)* (pow(_tam, 2) + pow(_tam, 2)));
	_Ibody[1][1] = ((mass / 12)* (pow(_tam, 2) + pow(_tam, 2)));
	_Ibody[2][2] = ((mass / 12)* (pow(_tam, 2) + pow(_tam, 2)));

	//Inversa
	mat3x3Inverse(_Ibodyinv, _Ibody);

	//Inicialización variables
	_position = origen;
	mat3x3Identity(_R);
	_omega = vec3Zero();
	_P = vec3Zero();
	_L = vec3Zero();

	/* I−1(t) = R(t)*Ibody−1*R(t)T*/
	mat3x3 RTrans, auxMul;
	mat3x3Identity(RTrans); mat3x3Identity(auxMul);
	mat3x3Transpose(RTrans, _R);
	mat3x3MultiplyMatrix(auxMul, _R, _Ibodyinv);
	mat3x3MultiplyMatrix(_Iinv, auxMul, RTrans);

	//mT
	mat4x4Identity(_M);

	//quat
	_Q = quatIdentity();

	coefRoz = 0;
	_vel = vec3Zero();
	_aceleracion = vec3Zero();
	_force = vec3Zero();
	_torque = vec3Zero();
	_impulse = vec3Zero();
	_fRoz = 0;
	_mass = mass;
	torqueAc = vec3Zero();
	forceAc = vec3Zero();
	_impulse = vec3Zero();

	vec3 asd = { 0.0f, 0.0f, 0.0f };
	FG_ = vec3Multiply(asd, _mass);

	

}


PeRigidBody::~PeRigidBody()
{
}


void PeRigidBody::update(float dT){

	computeForces();

	_position = vec3Add(_position, vec3Multiply(_vel,dT));

	/* Compute R˙(t) = ω(t)∗R(t) 
	mat3x3 RStar, Raux;
	mat3x3Identity(RStar); mat3x3Identity(Raux);
	mat3x3Star(RStar, _omega);
	mat3x3MultiplyMatrix(Raux, RStar, _R);
	mat3x3MultiplyScalar(Raux, dT);
	mat3x3Add(_R, _R, Raux);*/

	quat qOmega,quatMul;
	qOmega.w = 0; qOmega.x = _omega.x; qOmega.y = _omega.y; qOmega.z = _omega.z;
	quatMul = quatMultiply(qOmega, _Q);
	quatMul.w = quatMul.w * 0.5f * dT;
	quatMul.x = quatMul.x * 0.5f * dT;
	quatMul.y = quatMul.y * 0.5f * dT;
	quatMul.z = quatMul.z * 0.5f * dT;
	_Q = quatAdd(_Q, quatMul);
	
	/* d/dt P(t) = F(t) */
	_P = vec3Add(_P, vec3Multiply(_force, dT));
	/* d/dt L(t) = τ(t) */
	_L = vec3Add(_L, vec3Multiply( _torque,dT));

	/* v(t) = P(t)/M */
	_vel = vec3Divide(_P, _mass);

	/* ω(t) = I−1(t)L(t) */
	_omega = mat3x3MultiplyVector(_Iinv, _L);
	//Update R
	quaternionToMatrix(normalize());

	/* I−1(t) = R(t)*Ibody−1*R(t)T*/
	mat3x3 RTrans, auxMul;
	mat3x3Identity(RTrans); mat3x3Identity(auxMul);
	mat3x3Transpose(RTrans, _R);
	mat3x3MultiplyMatrix(auxMul, _R, _Ibodyinv);
	mat3x3MultiplyMatrix(_Iinv, auxMul, RTrans);

	//Matrices.
	mat4x4 T, Raux2;
	mat4x4Identity(T);
	mat4x4Identity(Raux2);
	mat4x4Identity(_M);
	T[0][3] = _position.x; T[1][3] = _position.y; T[2][3] = _position.z; 
	//mat4x4MultiplyMatrix(_M, T, getR4x4());
	getR4x4(Raux2);
	mat4x4MultiplyMatrix(_M, T, Raux2);
	
}

void PeRigidBody::addForce(PeFuerza nF){


	forceAc = vec3Add(forceAc, nF.GetDirectionVector());

}

void PeRigidBody::addTorque(PeFuerza nF){


	torqueAc = vec3Add(torqueAc, nF.GetDirectionVector());

}


void PeRigidBody::setRozamiento(bool r, float cR){

	coefRoz = cR;
	hasRozamiento = r;
	_fRoz = cR * std::abs(FG_.y);
	vec3 f;
	f.x = _fRoz;
	f.y = 0;
	f.z = 0;
	forceRoz = f;
}

void PeRigidBody::computeForces(){

	_force = vec3Zero();
	_torque = vec3Zero();

	addForce(FG_);
	_torque = torqueAc;
	_force = forceAc;

	
	forceAc = vec3Zero();
	torqueAc = vec3Zero();
}