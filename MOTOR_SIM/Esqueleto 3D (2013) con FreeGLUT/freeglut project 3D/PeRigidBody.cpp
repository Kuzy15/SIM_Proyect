#include "PeRigidBody.h"

PeRigidBody::PeRigidBody(vec3 origen, GLfloat tam)
{

	vec3 g;
	g.x = 0; g.y = -9.8; g.z = 0;
	vec3 v;

	_color.a = 1; _color.r = 0.5; _color.b = 0.5; _color.g = 0.5;
	_tam = tam;
	_position = origen;
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
void PeRigidBody::dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor4f(_color.r, _color.g, _color.b, _color.a);
	glTranslated(_position.x, _position.y, _position.z);
	glScalef(1, 1, 2);
	glutSolidCube(_tam);
	glPopMatrix();
}