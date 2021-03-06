#include "PeParticula.h"
#include <iostream>


PeParticula::PeParticula(float tam, float masa, float vida, vec3 pos, color3f color, vec3 velocidad, vec3 g, char t) :
	tam_(tam), masa_(masa), pos_(pos), color_(color), vida_(vida), t_(t)
{
	vidaRes_ = vida;
	activo_ = true;
	borrar_ = false;
	sec_ = glutGet(GLUT_ELAPSED_TIME);
	vel_ = velocidad;
	aceleracion_.x = 0; aceleracion_.z = 0;
	aceleracion_.y = 0;
	FuerzaG = g;

}


PeParticula::~PeParticula()
{

}

void PeParticula::dibuja() {

	if (activo_) {
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glColor4f(color_.r, color_.g, color_.b, color_.a);
		glTranslated(pos_.x, pos_.y, pos_.z);
		glutSolidSphere(tam_, 5, 5);
		glPopMatrix();
	}

}

void PeParticula::update(GLfloat deltaTime) {

	if (vidaRes_ <= 0 && vida_ != -1)
	{
		//borrar
		activo_ = false;
		borrar_ = true;
	}

	else
	{

		pos_ = vec3Add(pos_, vec3Add(vec3Multiply(vel_, deltaTime), vec3Divide(vec3Multiply(aceleracion_, (deltaTime * deltaTime)), 2)));
		if (t_ == 'h') {
			FuerzaG.x -= 0.005;
		}
		vel_ = vec3Add(vel_, vec3Multiply(vec3Add(aceleracion_, FuerzaG), deltaTime));

		if (vidaRes_ >= 0) {
			vidaRes_ = vidaRes_ - deltaTime;
		}

	}
	// SOLO PARA FUEGO
	if (t_ == 'f') {
		color_.r += vida_ / 1000;
		color_.g += vida_ / 1000;
	}

	//humo
	else {
		color_.r -= vida_ / 4000;
		color_.g -= vida_ / 4000;
		color_.b -= vida_ / 4000;
	}
}

