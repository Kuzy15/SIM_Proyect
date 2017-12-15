#include "PeRigidBody.h"
#include <iostream>

PeRigidBody::PeRigidBody(vec3 origen, float mass)
{

	_tam = 2;

	c.a = this;

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

	coefRoz = 0;
	_vel = vec3Zero();
	_aceleracion = vec3Zero();
	_force = vec3Zero();
	_torque = vec3Zero();
	_impulse = vec3Zero();
	_fRoz = 0;
	_mass = mass;
	_impulse = vec3Zero();

	FG_ = vec3Multiply(G, _mass);

}


PeRigidBody::~PeRigidBody()
{
}


void PeRigidBody::update(float dT){

	computeForces();

	_position = vec3Add(_position, vec3Multiply(_vel,dT));

	/* Compute R˙(t) = ω(t)∗R(t) */
	/*mat3x3 RStar, Raux;
	mat3x3Identity(RStar); mat3x3Identity(Raux);
	mat3x3Star(RStar, _omega);
	mat3x3MultiplyMatrix(Raux, RStar, _R);
	mat3x3MultiplyScalar(Raux, dT);
	mat3x3Add(_R, _R, Raux);*/

	/* d/dt P(t) = F(t) */
	_P = vec3Add(_P, vec3Multiply(_force, dT));
	/* d/dt L(t) = τ(t) */
	_L = vec3Add(_L, vec3Multiply( _torque,dT));

	/* v(t) = P(t)/M */
	_vel = vec3Divide(_P, _mass);

	/* ω(t) = I−1(t)L(t) */
	_omega = mat3x3MultiplyVector(_Iinv, _L);

	/* I−1(t) = R(t)*Ibody−1*R(t)T*/
	/*mat3x3 RTrans, auxMul;
	mat3x3Identity(RTrans); mat3x3Identity(auxMul);
	mat3x3Transpose(RTrans, _R);
	mat3x3MultiplyMatrix(auxMul, _R, _Ibodyinv);
	mat3x3MultiplyMatrix(_Iinv, auxMul, RTrans);*/
	

	//ComputeForces y Torque

	//VIEJO_position = vec3Add(_position, vec3Add(vec3Multiply(_vel, dT), vec3Divide(vec3Multiply(_aceleracion, (dT * dT)), 2)));
	
	//Reseteamos las fuerzas de impulso*/

	_impulse = vec3Zero();
}

void PeRigidBody::addForce(PeFuerza nF){


	_force = vec3Add(_force, nF.GetDirectionVector());

}

void PeRigidBody::addTorque(PeFuerza nF){


	_torque = vec3Add(_torque, nF.GetDirectionVector());

}

void PeRigidBody::applyForce(PeFuerza nI){

	_impulse = vec3Add(_impulse, nI.GetDirectionVector());

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

	//addForce(FG_);
	vec3 t = vec3Zero();
	t.x = 0.1;

	addTorque(t);
	

}

//Devuelve true si hay colisión
bool PeRigidBody::colliding(PeRigidBody* r)
{
	c.b = r;
	if (c.b == c.a){
		return false;
	}
	vec3 padot = c.a->getVel(),
		pbdot = c.b->getVel();
	vec3 xi;
	xi.x = padot.x - pbdot.x;
	xi.y = padot.y - pbdot.y;
	xi.z = padot.z - pbdot.z;

	c.n.x = c.a->getPos().x - c.b->getPos().x;
	c.n.y = c.a->getPos().y - c.b->getPos().y;
	c.n.z = c.a->getPos().z - c.b->getPos().z;
	double vrel = c.n.x * xi.x + c.n.y * xi.y + c.n.z * xi.z;    /* v−rel */
	
	return vrel <= 0;          /*resting contact*/

}
