#include "ObjetoCuadrico.h"


ObjetoCuadrico::ObjetoCuadrico(){

	obj = gluNewQuadric(); 

}


ObjetoCuadrico::~ObjetoCuadrico()
{
	gluDeleteQuadric(obj);
}
