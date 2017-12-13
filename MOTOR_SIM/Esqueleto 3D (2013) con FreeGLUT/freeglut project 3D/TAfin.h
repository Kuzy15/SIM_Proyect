#ifndef TAFIN_H
#define TAFIN_H
class TAfin
{
public:

	TAfin()
	{
		m = new GLfloat[16];

		for (int i = 0; i < 16; i++) m[i] = 0;
		m[0] = m[5] = m[10] = m[15] = 1;
		
	}

	~TAfin()
	{
	}

	void traslada(GLfloat x, GLfloat y, GLfloat z)
	{
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(x, y, z);
		GLfloat m1[16];
		//Dejar la matriz actual de modelado-vista en m1
		//Los 16 datos están enumerados por columnas
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
		glPopMatrix();
		postMultiplica(m1);

	}

	void rota(float* r)
	{
		glMatrixMode(GL_MODELVIEW);
		postMultiplica(r);
	}

	void escala(GLfloat x, GLfloat y, GLfloat z) 
	{
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glScalef(x, y, z);
		GLfloat m1[16];
		//Dejar la matriz actual de modelado-vista en m1
		//Los 16 datos están enumerados por columnas
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
		glPopMatrix();
		postMultiplica(m1);
	}

	void postMultiplica(GLfloat* m1)
	{
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		//Cargar m como matriz actual de modelado-vista
		glLoadMatrixf(m);
		//Post-multiplicar por m1
		glMultMatrixf(m1);
		//Dejar el resultado en m
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
		glPopMatrix();
	}


	GLfloat* getM(){
		return m;
	}

	void reset(){
	
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		GLfloat m1[16];
		//Dejar la matriz actual de modelado-vista en m1
		//Los 16 datos están enumerados por columnas
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
		glPopMatrix();
		postMultiplica(m1);

	}

protected:
	
	GLfloat* m; //matriz de transformación
};

#endif 