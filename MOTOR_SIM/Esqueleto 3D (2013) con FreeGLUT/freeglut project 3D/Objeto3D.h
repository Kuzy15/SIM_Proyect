#ifndef OBJETO3D_H
#define OBJETO3D_H

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <vector>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include "TAfin.h"

class Objeto3D
{
public:

	Objeto3D()
	{
		mT = new TAfin();

	}

	virtual ~Objeto3D()
	{
		delete mT;
	}

	virtual void dibuja() = 0;

	TAfin* getMatriz(){ return mT; }

protected:
	TAfin* mT;
};

#endif