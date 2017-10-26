#include "PeSPExplosion.h"
#include <iostream>
#include "PeMundo.h"
//ES DE COLIN
//retocar, si no, copy== true;
PeSPExplosion::PeSPExplosion(vec3 origen, int maxParticulas, float vida, float kvd) :PeSistemaParticulas(origen, maxParticulas, vida, kvd)

{
		origen_.y = 0;
		origen_.x = 0;
		origen_.z = 0;
		color3f c;
		c.r = 1;
		c.g = 1;
		c.b = 0;
		
		cohete = new PeParticula(0.5, 20, 10, origen_,c );
		
		
		vec3 a;
		a.x = 0; a.y = 3.2; a.z = 0;
		cohete->vel_ = a;
		particulas_.push_back(cohete);
		needExplo = true;
		


}


PeSPExplosion::~PeSPExplosion()
{
}

bool PeSPExplosion::SimulaPasoParticula(PeParticula*p, float deltaTime){

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
		std::cout << "---------------" << endl;*/

		return true;
	}

}

bool PeSPExplosion::SimulaPasoParticula(PeParticula*p, vec3 a, float deltaTime){ return true; }

void PeSPExplosion::addFuerza(vec3 f){
	for (auto w : particulas_)
		w->AddFuerza(f);
}

void PeSPExplosion::creaPalmera(vec3 ignicion){

	color3f col;
	col.r = 0.92;
	col.g = 0.61;
	col.b = 0.03;
	for (int i = 0; i < 100; i++){
		origen_.x = ignicion.x;
		origen_.y = ignicion.y;
		origen_.z = ignicion.z;
		
		particulas_.push_back(new PeParticula(0.5, 20, 100, origen_, col));
	}



}