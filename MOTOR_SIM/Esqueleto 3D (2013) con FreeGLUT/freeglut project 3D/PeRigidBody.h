#ifndef PERIGIDBODY_H
#define PERIGIDBODY_H

#include "ObjetosCuadricos.h"
#include "ccVector.h"
#include "PeFuerza.h"

class PeRigidBody
{
public:
	PeRigidBody(vec3 origen, GLfloat tam, GLfloat mass);
	virtual ~PeRigidBody();
	void update(float dT);
	void addForce(PeFuerza nF);
	void applyForce(PeFuerza impulse, vec3 point);
	void applyTorque(const vec3 & torque);
	void calculateMassCenter();
	void calculateInertiaMoment(float ancho, float alto);// De momento solo calculamos el momento de inercia del cubo.
	void calculateTorque();
	void dibuja();

	vec3 calculateDistanceOfForce(float x, float y, float z);
	void updateRotationMoment(float delta);
	
private:
	
	float _mass;
	float _inertiaMomemtum;
	vec3 _position;
	vec3 _vel;
	vec3 _angularMomemtum;
	vec3 _angularVel;
	vec3 _force;
	vec3 _torque;
	vec3 _aceleracion;
	vec3 _impulse;
	vec3 _massCenter;
	vec3 _I;
	mat3x3 _R;
	GLfloat _sec;
	struct color3f {
		GLfloat r;
		GLfloat g;
		GLfloat b;
		GLfloat a;
	};
	color3f _color;
	vec3 FG;




	vec3 _point;
	
};

#endif