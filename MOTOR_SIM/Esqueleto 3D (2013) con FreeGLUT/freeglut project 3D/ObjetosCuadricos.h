#ifndef OBJETOS_CUADRICOS_H
#define OBJETOS_CUADRICOS_H

#include "ObjetoCuadrico.h"

//Cilindro
class Cilindro :
	public  ObjetoCuadrico {
public:
	Cilindro(GLfloat radioBase, GLfloat radioTop, GLfloat altura, int slices = 20, int stacks = 10) :radioBase_(radioBase),
		radioTop_(radioTop), altura_(altura), slices_(slices), stacks_(stacks){};

	virtual ~Cilindro(){};
	virtual void dibuja();
private:
	GLfloat radioBase_, radioTop_, altura_;
	int slices_, stacks_;
};

//Esfera
class Esfera :
	public ObjetoCuadrico{
public:

	Esfera(GLfloat radio, int slices = 10, int stacks = 10): radio_(radio), slices_(slices), stacks_(stacks){};
	virtual ~Esfera(){};
	virtual void dibuja();

private:
	GLfloat radio_;
	int slices_, stacks_;
};

//Disco
class Disco :
	public ObjetoCuadrico {
public:
	Disco(GLfloat radioDentro, GLfloat radioFuera, int slices, int rings) :radioDentro_(radioDentro),
		radioFuera_(radioFuera), slices_(slices), rings_(rings){};
	virtual ~Disco(){};
	virtual void dibuja();
private:
	GLfloat radioDentro_, radioFuera_;
	int slices_, rings_;
};

//DiscoParcial
class DiscoParcial :
	public ObjetoCuadrico {
public:
	DiscoParcial(GLfloat radioDentro, GLfloat radioFuera, GLfloat stA, GLfloat swA,int slices, int rings) :radioDentro_(radioDentro),
		radioFuera_(radioFuera), slices_(slices), rings_(rings), startAngle_(stA),sweepAngle_(swA){};
	virtual ~DiscoParcial(){};
	virtual void dibuja();
private:
	GLfloat radioDentro_, radioFuera_, startAngle_, sweepAngle_;
	int slices_, rings_;

};

//Cubo
class Cubo :
	public ObjetoCuadrico {
public:
	Cubo(GLfloat size) : size_(size){};
	virtual ~Cubo(){};
	virtual void dibuja();
private:
	GLfloat size_;

};

#endif