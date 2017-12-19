#include "ObjetosCuadricos.h"

//Metodos Cilindro
void Cilindro::dibuja(){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glMultMatrixf(mT->getM());
	gluCylinder(obj, radioBase_, radioTop_, altura_, slices_, stacks_);

	glPopMatrix();

}



//Metodos Esfera
void Esfera::dibuja(){


	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glMultMatrixf(mT->getM());
	gluSphere(obj, radio_, slices_, stacks_);

	glPopMatrix();
}


//Metodos Disco
void Disco::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glMultMatrixf(mT->getM());
	gluDisk(obj, radioDentro_, radioFuera_, slices_, rings_);

	glPopMatrix();
}



//Metodos DiscoParcial
void DiscoParcial::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glMultMatrixf(mT->getM());
	gluPartialDisk(obj, radioDentro_, radioFuera_, slices_, rings_,startAngle_,sweepAngle_);

	glPopMatrix();

}

void Cubo::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glMultMatrixf(mT->getM());
	glutSolidCube(size_);
	glPopMatrix();

}