#ifndef PESPFUEGO
#define PESPFUEGO
#include "PeSistemaParticulas.h"
class PeSPFuego :
	public PeSistemaParticulas
{
public:
	PeSPFuego(vec3 origen, int maxParticulas, float vida, /*float varVida, flaot varTam*/float kvd, char t);
	virtual ~PeSPFuego();

	virtual void update(GLfloat deltaTime);
	virtual void addFuerza(vec3 f);
private:
	vec3 v;
	color3f c;
	vec3 g;
	char _t; //tipo
	int numPart;
	GLfloat x, y, z;
};

#endif