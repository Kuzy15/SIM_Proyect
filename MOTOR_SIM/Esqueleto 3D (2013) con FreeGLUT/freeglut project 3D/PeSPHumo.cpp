#include "PeSPHumo.h"
#include <iostream>
#include "PeMundo.h"

GLfloat dameRandomHola(GLfloat max, GLfloat min) {
	return min + static_cast <GLfloat> (rand()) / (static_cast <GLfloat> (RAND_MAX / (max - min)));
}

PeSPHumo::PeSPHumo(vec3 origen, int maxParticulas, float vida, float kvd) :PeSistemaParticulas(origen, maxParticulas, vida, kvd)
{
	

	color3f col;
	col.r = 0.92;
	col.g = 0.61;
	col.b = 0.03;
	for (int i = 0; i < 100; i++){
		
		origen_.y = 0;
		origen_.x = dameRandomHola(5,-5);
		origen_.z = dameRandomHola(5, -5);

		vec3 v1;

		v1.x = dameRandomHola(0.5,-0.5);
		v1.y = 2;
		v1.z = dameRandomHola(0.5, -0.5);

		
		PeParticula* p = new PeParticula(0.5, 20, 100, origen_, col);
		p->SetVel(v1);
		particulas_.push_back(p);
	}

	
	
}


PeSPHumo::~PeSPHumo()
{
}




bool PeSPHumo::SimulaPasoParticula(PeParticula*p, float deltaTime){

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
		p->pos_ = vec3Add(p->pos_, (vec3Multiply(p->vel_, deltaTime)));
		p->vel_ = vec3Add(vec3Multiply(vec3Divide(p->fuerzas_, p->masa_), deltaTime), p->vel_);

		vec3 tras = p->pos_;
		p->traslacion_ = vec3Subtract(tras, aux);
		std::cout << p->fuerzas_.y << std::endl;
		/*std::cout << "Velocidad: " << p->vel_.y << endl;
		std::cout << "Posicion: "<< p->pos_.x << " " << p->pos_.y << " " << p->pos_.z << endl;
		std::cout << "---------------" << endl;*/

		return true;
	}

}

bool PeSPHumo::SimulaPasoParticula(PeParticula*p, vec3 a, float deltaTime){ return true; }

void PeSPHumo::addFuerza(vec3 f){
	for (auto w : particulas_)
		w->AddFuerza(f);
}

void PeSPHumo::creaPalmera(vec3 ignicion){

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