#include "PeRigidBody.h"
#include <iostream>

PeRigidBody::PeRigidBody(vec3 origen, float mass)
{

	//Tensor de inercia. BUSCAR TAM
	_Ibody[0][0] = ((mass / 12)* (pow(_tam, 2) + pow(_tam, 2)));
	_Ibody[1][1] = ((mass / 12)* (pow(_tam, 2) + pow(_tam, 2)));
	_Ibody[2][2] = ((mass / 12)* (pow(_tam, 2) + pow(_tam, 2)));

	//Inversa
	mat3x3Inverse(_Ibodyinv, _Ibody);

	//Inicializaci�n variables
	_position = origen;
	mat3x3Identity(_R);
	_P = vec3Zero();
	_L = vec3Zero();

	coefRoz = 0;
	_vel = vec3Zero();
	_aceleracion = vec3Zero();
	_force = vec3Zero();
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

	_position = vec3Add(_position, vec3Add(vec3Multiply(_vel, dT), vec3Divide(vec3Multiply(_aceleracion, (dT * dT)), 2)));
	_vel = vec3Add(_vel, vec3Multiply(_aceleracion, dT));
	if (hasRozamiento){
		if (!(_vel.x < 0.05 && _vel.x > -0.05)){
			applyForce(forceRoz);
		}
		else{
			_position.x = 0;
		}
		std::cout << "Vel " << _position.x << std::endl;
	}
	_aceleracion = vec3Divide(vec3Add(_force, _impulse), _mass);
	//Reseteamos las fuerzas de impulso
	_impulse = vec3Zero();
}

void PeRigidBody::addForce(PeFuerza nF){


	_force = vec3Add(_force, nF.GetDirectionVector());

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
