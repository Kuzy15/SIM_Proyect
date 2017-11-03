#ifndef PESISTEMAPARTICULAS_H
#define PESISTEMAPARTICULAS_H


#include <list>
#include "PeParticula.h"
using namespace std;

class PeSistemaParticulas
{
protected:

	vec3 origen_;

	list<PeParticula*> particulas_;

	int maxParticulas_;

	float vida_;

	float varVida_;

	float varTam_;

	float Kvd_;

public:
	GLfloat dameRandom(GLfloat max, GLfloat min) {
		return min + static_cast <GLfloat> (rand()) / (static_cast <GLfloat> (RAND_MAX / (max - min)));
	}
	vec3 DameVectorAleatorio(GLfloat magnitud) {
		vec3 v;
		GLfloat phi = dameRandom(3.1415f, 0.0f);
		GLfloat cosTheta = dameRandom(1, -1);

		GLfloat theta = acosf(cosTheta);
		GLfloat x = sinf(theta)*cosf(phi), y = sinf(theta)*sinf(phi), z = cosf(theta);
		v.x = x;
		v.y = y;
		v.z = z;
		v = vec3Multiply(v,magnitud);
		return v;
	}
	PeSistemaParticulas(vec3 origen, int maxParticulas, float vida, /*float varVida, flaot varTam*/float kvd);

	virtual ~PeSistemaParticulas();

	inline list<PeParticula*> getParticulas(){ return particulas_; };

	inline float getNumParticulas(){ return particulas_.size(); }

	void const addParticula(PeParticula*);

	virtual void update(GLfloat deltaTime) = 0;

	virtual void addFuerza(vec3 f) = 0;

	//virtual bool destroy() = 0;

	void dibuja();

};

#endif