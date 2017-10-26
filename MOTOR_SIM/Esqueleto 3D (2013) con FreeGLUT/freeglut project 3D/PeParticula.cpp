#include "PeParticula.h"
GLfloat dameRandom(GLfloat max, GLfloat min) {
	return min + static_cast <GLfloat> (rand()) / (static_cast <GLfloat> (RAND_MAX / (max - min)));
}

PeParticula::PeParticula(float tam, float masa, float vida, vec3 pos, color3f color) : tam_(tam), masa_(masa), pos_(pos), color_(color), vidaRes_(vida), sec_(GLUT_ELAPSED_TIME)
{
	render_ = gluNewQuadric();

	vec3 ini;
	vec3 hey;
	vec3 g;
	g.x = 0; g.y = -9.8; g.z = 0;

	hey.x = 0; hey.y = 0; hey.z = 0;
	ini.x = dameRandom(1.5, -1.5); ini.y = dameRandom(0, 1); ini.z = dameRandom(1.5, -1.5);
	fuerzas_ = hey;
	AddFuerza(g);
	vel_ = ini;
	aceleracion_ = hey;
	traslacion_ = hey;
	activo_ = true;


}


PeParticula::~PeParticula()
{
	delete render_;
	render_ = nullptr;
}

void PeParticula::dibuja(){
	//set color
	
	color_.g -= (vidaRes_/1000);

	//update();
	if (activo_){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glColor3f(color_.r, color_.g, color_.b);
		glTranslated(pos_.x, pos_.y, pos_.z);

		glutSolidSphere(0.2, 10, 10);
		glPopMatrix();
	}
	
}
