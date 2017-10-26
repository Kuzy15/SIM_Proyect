#include "PeParticula.h"


PeParticula::PeParticula(float tam, float masa, float vida, vec3 pos, vec3 color) : tam_(tam), masa_(masa), pos_(pos), color_(color), vidaRes_(vida)
{
	render_ = gluNewQuadric();

	vec3 ini;
	ini.x = 0; ini.y = 0; ini.z = 0;
	fuerzas_ = ini;
	vel_ = ini;
	aceleracion_ = ini;
	traslacion_ = ini;
}


PeParticula::~PeParticula()
{
	delete render_;
	render_ = nullptr;
}

void PeParticula::dibuja(){
	//set color
	//update();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(pos_.x, pos_.y, pos_.z);
	glutSolidSphere(0.2, 10, 10);
	glPopMatrix();
	
}
