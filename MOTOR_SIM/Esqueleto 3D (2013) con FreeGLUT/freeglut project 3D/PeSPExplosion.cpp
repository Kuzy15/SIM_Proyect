#include "PeSPExplosion.h"
#include <iostream>


PeSPExplosion::PeSPExplosion(vec3 origen, int maxParticulas, float vida, float kvd) :PeSistemaParticulas(origen, maxParticulas, vida, kvd)

{
	origen_.x = 1;
	origen_.y = 3;
	origen_.z = 1;
	for (int i = 0; i < maxParticulas_; i++){
		particulas_.push_back(new PeParticula(0.5, 2,vida, origen_, origen_));
	}
	

}


PeSPExplosion::~PeSPExplosion()
{
}

bool PeSPExplosion::SimulaPasoParticula(PeParticula*p, float deltaTime){

	if (p->vidaRes_ <= 0 && vida_ != -1)
	{
		//borrar
		p->traslacion_ = vec3Zero();
		
		return false;
	}
	else
	{
		vec3 aux = p->pos_;

		if (vida_ != -1)
			p->vidaRes_ -= deltaTime;
		p->fuerzas_ = vec3Add( p->fuerzas_, vec3Multiply(p->vel_,-Kvd_));
		p->pos_ = vec3Add(p->pos_,(vec3Multiply(p->vel_, deltaTime)));
		p->vel_ = vec3Add(vec3Multiply(vec3Divide(p->fuerzas_, p->masa_), deltaTime),p->vel_);
		
		vec3 tras = p->pos_;
		p->traslacion_ = vec3Subtract(tras, aux);
		/*std::cout << "Velocidad: " << p->vel_.y << endl;
		std::cout << "Posicion: "<< p->pos_.x << " " << p->pos_.y << " " << p->pos_.z << endl;
		std::cout << "---------------" << endl;*/

		return true;
	}

}

bool PeSPExplosion::SimulaPasoParticula(PeParticula*p, vec3 a, float deltaTime){ return true; }

void PeSPExplosion::addFuerza(vec3 f){
	for (auto w : particulas_)
		w->AddFuerza(f);
}