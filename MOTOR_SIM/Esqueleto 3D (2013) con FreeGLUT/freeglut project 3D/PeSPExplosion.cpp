#include "PeSPExplosion.h"
#include <iostream>
#include "PeMundo.h"

PeSPExplosion::PeSPExplosion(vec3 origen, int maxParticulas, float vida, float kvd) :PeSistemaParticulas(origen, maxParticulas, vida, kvd)

{
	vec3 g;
	g.x = 0; g.y = -2.8 ; g.z = 0;
	vec3 v;
	color3f c;
	c.a = 1; c.r = 1; c.b = 0; c.g = 0;

	for (int i = 0; i < maxParticulas_; i++){
		v = DameVectorAleatorio(dameRandom(5,-5));

		PeParticula* p = new PeParticula(0.1f, 1.0f, 100.0f, origen_, c, v,g);
		particulas_.push_back(p);
		
	}
}


PeSPExplosion::~PeSPExplosion()
{
}

/*bool PeSPExplosion::SimulaPasoParticula(PeParticula*p, float deltaTime){

	deltaTime -= p->sec_;
	deltaTime /= 10000;
	if (p->vidaRes_ <= 0 && vida_ != -1)
	{
		//borrar
		p->traslacion_ = vec3Zero();
		p->activo_ = false;
		
		
		if (!cohete->activo_ && needExplo){
			creaPalmera(p->GetPos());
			needExplo = false;
		}
		return false;
	}
	else
	{
		vec3 aux = p->pos_;
		vec3 g;
		g.x = 0; g.y = 0; g.z = 0;
		
		if (vida_ != -1)
			p->vidaRes_ -= deltaTime;
		//p->fuerzas_ = vec3Add( p->fuerzas_, g );
		p->pos_ = vec3Add(p->pos_,(vec3Multiply(p->vel_, deltaTime)));
		p->vel_ = vec3Add(vec3Multiply(vec3Divide(p->fuerzas_, p->masa_), deltaTime),p->vel_);
		
		vec3 tras = p->pos_;
		p->traslacion_ = vec3Subtract(tras, aux);
		std::cout << p->fuerzas_.y << std::endl;
		/*std::cout << "Velocidad: " << p->vel_.y << endl;
		std::cout << "Posicion: "<< p->pos_.x << " " << p->pos_.y << " " << p->pos_.z << endl;
		std::cout << "---------------" << endl;

		return true;
	}

}

bool PeSPExplosion::SimulaPasoParticula(PeParticula*p, vec3 a, float deltaTime){ return true; }
*/
void PeSPExplosion::addFuerza(vec3 f){
	for (auto w : particulas_)
		w->AddFuerza(f);
}


void PeSPExplosion::update(GLfloat deltaTime){
	for (auto w : particulas_){
		w->update(deltaTime);
		//borrar
	}
}