#include "PeRigidBody.h"
#include <iostream>

PeRigidBody::PeRigidBody(vec3 origen, GLfloat tam, GLfloat mass)
{
	_sec = glutGet(GLUT_ELAPSED_TIME);
	_vel = vec3Zero();
	_aceleracion = vec3Zero();
	_force = vec3Zero();
	_impulse = vec3Zero();




	_color.a = 1; _color.r = 0.5; _color.b = 0.5; _color.g = 0.5;
	_tam = tam;
	_mass = mass;
	_position = origen;
	_impulse = vec3Zero();

	FG = vec3Multiply(G, _mass);
	//Gravedad
	addForce(PeFuerza(FG));
	vec3 f; f.x = 1000; f.y = 0; f.z = 0;
	applyForce(PeFuerza(f));
}


PeRigidBody::~PeRigidBody()
{
}


void PeRigidBody::update(float dT){

	_position = vec3Add(_position, vec3Add(vec3Multiply(_vel, dT), vec3Divide(vec3Multiply(_aceleracion, (dT * dT)), 2)));
	//_vel = vec3Add(_vel, vec3Multiply(vec3Add(_aceleracion, FG), dT));
	_vel = vec3Add(_vel, vec3Multiply(_aceleracion, dT));
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
void PeRigidBody::dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor4f(_color.r, _color.g, _color.b, _color.a);
	glTranslated(_position.x, _position.y, _position.z);
	glScalef(1, 1, 2);
	glutSolidCube(_tam);
	glPopMatrix();
}