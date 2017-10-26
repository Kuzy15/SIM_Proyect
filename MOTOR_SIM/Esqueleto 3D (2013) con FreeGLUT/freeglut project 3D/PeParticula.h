#ifndef PEPARTICULA_H
#define PEPARTICULA_H
//OpenGL siempre antes que el ccVector
#include "ObjetosCuadricos.h"
#include "ccVector.h"

class PeParticula
{

public:

	float masa_;
	vec3 pos_;
	vec3 traslacion_;
	vec3 vel_;
	vec3 fuerzas_;
	vec3 aceleracion_;
	float vidaRes_;
	float tam_;
	vec3 color_;

	GLUquadric* render_;

public:
	PeParticula(float tam, float masa, float vida, vec3 pos, vec3 color);
	virtual ~PeParticula();

	void dibuja();

	inline void update(){
		
		//render_->getMatriz()->traslada(traslacion_.x, traslacion_.y, traslacion_.z);
	};

	inline vec3 GetPos(){ return pos_; };
	inline vec3 GetVel(){ return vel_; };
	inline void SetVel(vec3 v){ vel_ = v; };
	//inline vector_3 GetForce(){return f;};
	inline void SetFuerza(vec3 f){ fuerzas_ = f; };
	inline void AddFuerza(vec3 f){ fuerzas_ = vec3Add(fuerzas_, f);};
	inline float GetVida(){ return vidaRes_; };
	inline float GetTam(){ return tam_; };
	inline vec3 GetColor(){ return color_; };
	
};

#endif
