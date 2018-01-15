#ifndef PEPARTICULA_H
#define PEPARTICULA_H
//OpenGL siempre antes que el ccVector
#include "ObjetosCuadricos.h"
#include "ccVector.h"
struct color3f {
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
};
class PeParticula
{

private:

	float masa_;
	float vida_;
	float vidaRes_;
	float tam_;
	bool activo_;
	bool borrar_;
	vec3 pos_;
	vec3 vel_;
	vec3 fuerzas_;
	vec3 aceleracion_;
	vec3 FuerzaG;
	GLfloat sec_;

	color3f color_;
	char t_;
public:
	PeParticula(float tam, float masa, float vida, vec3 pos, color3f color, vec3 fuerza, vec3 g, char t);
	virtual ~PeParticula();

	void dibuja();

	void update(GLfloat deltaTime);

	inline vec3 GetPos() { return pos_; };
	inline void SetPos(vec3 p) { pos_ = p; };
	inline vec3 GetVel() { return vel_; };
	inline void SetVel(vec3 v) { vel_ = v; };
	//inline vector_3 GetForce(){return f;};
	inline void SetFuerza(vec3 f) { fuerzas_ = f; };
	inline void AddFuerza(vec3 f) { fuerzas_ = vec3Add(fuerzas_, f); };
	inline bool isAlive() { return borrar_; };
	inline float GetVida() { return vidaRes_; };
	inline float GetTam() { return tam_; };
	inline color3f GetColor() { return color_; };
	inline bool isActive() { return activo_; };
	inline bool needDelete() { return borrar_; };

};

#endif
