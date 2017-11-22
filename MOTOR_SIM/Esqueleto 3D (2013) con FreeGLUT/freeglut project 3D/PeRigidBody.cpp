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
	_mass = mass;
	_position = origen;
	_impulse = vec3Zero();

	FG = vec3Multiply(G, _mass);
	//Gravedad
	addForce(PeFuerza(FG));
	vec3 f; f.x = 1000; f.y = 0; f.z = 0;
	//applyForce(PeFuerza(f));
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			_R[i][j] = 0;
		}
	}
	_R[0][0] = 1;
	_R[1][1] = 1;
	_R[2][2] = 1;

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

void PeRigidBody::applyForce(PeFuerza nI, vec3 point){

	_impulse = vec3Add(_impulse, nI.GetDirectionVector());
	_point = point;
}
void PeRigidBody::dibuja() {
/*	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor4f(_color.r, _color.g, _color.b, _color.a);
	glTranslated(_position.x, _position.y, _position.z);
	glScalef(1, 1, 2);
	glutSolidCube(_tam);
	glPopMatrix();*/
}


void PeRigidBody::applyTorque(const vec3 & torque){

	//_torque += torque;
} 

void PeRigidBody::calculateMassCenter(){

	vec3 massCenter;

	float weight = _mass * 9.8;
	massCenter.x = (_position.x * weight) / (_mass * 9.8);
	massCenter.y = (_position.y * weight) / (_mass * 9.8);
	massCenter.z = (_position.z * weight) / (_mass * 9.8);

	_massCenter = massCenter;
}

void PeRigidBody::calculateInertiaMoment(float ancho, float alto){

	calculateMassCenter();
	float d = (_position.x - _massCenter.x) * (_position.x - _massCenter.x) + (_position.y - _massCenter.y) * (_position.y - _massCenter.y) + 
		(_position.z - _massCenter.z) * (_position.z - _massCenter.z);// Para el cubo esta operacion es 0.

	//el momento de inercia respecto de un eje perpendicular a dos caras y paralelo a los lados de longitud c vale:
	 float I = (_mass* ((ancho * ancho) + (alto * alto))) / 12 + (_mass * std::pow(d,2));
	// _I = I;
	
	

}


void PeRigidBody::updateRotationMoment(float delta){

	vec3 aux;
	/*aux.x = _R[0][0];
	aux.y = _R[1][0];
	aux.z = _R[2][0];*/
	aux = mat3x3GetCol(_R, 0);
	aux = vec3CrossProduct(aux, vec3Multiply(_angularVel, delta));

	vec3 aux2;
	aux2 = mat3x3GetCol(_R, 0);
	aux2 = vec3Add(aux2, aux);

}

void PeRigidBody::calculateTorque(){//considerando que la fuerza se hace perpendicular al eje de rotacion
	calculateInertiaMoment(10, 10); //ej

	vec3 torque;//I*accangular
	vec3 acc = vec3Divide(_force, _mass);//de la fuerza sacas acc

	vec3 acg;
	acg.x = acc.x / calculateDistanceOfForce(_point.x, _point.y, _point.z).x;
	acg.y = acc.y / calculateDistanceOfForce(_point.x, _point.y, _point.z).y;
	acg.z = acc.z / calculateDistanceOfForce(_point.x, _point.y, _point.z).z;

	torque = vec3Multiply(acg, _I);
}

vec3 PeRigidBody::calculateDistanceOfForce(float x, float y, float z){
	vec3 dist;
	dist.x = x - _massCenter.x;
	dist.y = y - _massCenter.y;
	dist.z = z - _massCenter.z;

	if (dist.x == 0 && dist.y == 0 && dist.z == 0){
		dist.x = 1;
		dist.y = 1;
		dist.z = 1;
	}
	return dist;

}