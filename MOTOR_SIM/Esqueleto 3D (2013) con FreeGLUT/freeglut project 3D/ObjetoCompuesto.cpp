#include "ObjetoCompuesto.h"


ObjetoCompuesto::ObjetoCompuesto() : numHijos(0)
{
	hijos.reserve(10000);
}


ObjetoCompuesto::~ObjetoCompuesto()
{

	for (int i = 0; i < numHijos; i++)
		delete hijos[i];

}

void ObjetoCompuesto::dibuja(){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(this->mT->getM());

	for (int i = 0; i < numHijos; i++)
		hijos[i]->dibuja();

	glPopMatrix();
}

void ObjetoCompuesto::addObjeto(Objeto3D* obj){

	hijos.push_back(obj);
	numHijos++;

}
