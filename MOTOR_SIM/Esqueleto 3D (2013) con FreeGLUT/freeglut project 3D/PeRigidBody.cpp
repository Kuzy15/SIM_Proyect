#include "PeRigidBody.h"

PeRigidBody::PeRigidBody()
{
	_impulse = vec3Zero();
	//Gravedad
	addForce(PeFuerza(FG));
	
}


PeRigidBody::~PeRigidBody()
{
}


void PeRigidBody::update(float dT){

	_position = vec3Add(_position, vec3Add(vec3Multiply(_vel, dT), vec3Divide(vec3Multiply(_acceleracion, (dT * dT)), 2)));
	_vel = vec3Add(_vel, vec3Multiply(_acceleracion, dT));
	_acceleracion = vec3Divide(vec3Add(_force,_impulse), _mass);

	//Reseteamos las fuerzas de impulso
	_impulse = vec3Zero();
}

void PeRigidBody::addForce(PeFuerza nF){


	_force = vec3Add(_force, nF.GetDirectionVector());

}

void PeRigidBody::applyForce(PeFuerza nI){

	_impulse = vec3Add(_impulse, nI.GetDirectionVector());

}