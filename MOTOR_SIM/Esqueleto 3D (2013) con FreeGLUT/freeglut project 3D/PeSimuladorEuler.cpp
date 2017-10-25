#include "PeSimuladorEuler.h"


PeSimuladorEuler::PeSimuladorEuler(PeMundo* pMundo) : PeSimulador(pMundo)
{

}


PeSimuladorEuler::~PeSimuladorEuler()
{
}

void PeSimuladorEuler::Simular(float time)
{
	float deltaTime;

	while (lastTime_ < time)
	{
		deltaTime = time - lastTime_;
		if (deltaTime > maxTiempoPaso_)
		{
			deltaTime = maxTiempoPaso_;
		}

		//Simulamos todas las fuerzas y guardamos la suma de todas
		/*
		for (int i = 0; i< pMundo_->GetNumForces(); i++)
		{
			pMundo_->GetForce(i)->SimulateStepForce(time);
			ForceAc = pMundo_->GetForce(i)->GetForce();
		}*/
		PeFuerza* f;
		list<PeFuerza*> fuerzas = pMundo_->getFuerzas();
		list<PeFuerza*>::iterator it = fuerzas.begin();
		while (it != fuerzas.end()){
			f = *it;
			f->SimulaPasoFuerza(time);
			ForceAc = vec3Add(ForceAc, f->GetFuerza());
			it++;
		}

		//TODO: Simular a intervalos distintos las partículas y solidos
		/*SimulateBodies(DeltaTime);
		SimulateParticles(DeltaTime);*/

		lastTime_ += deltaTime;
	}
}


void PeSimuladorEuler::SimulaParticulas(float deltaTime)
{
	PeSistemaParticulas* sP;
	PeParticula *p;
	bool collisionCheck;
	vec3 gravForce;
	//Simulation Step, unary force

	/*for (int i = 0; i <p->GetNumParticleSprings(); i++)
	{
		CParticleSpring* ps = pWorld->GetParticleSpring(i);
		ps->ApplyForces();
	}*/
	
	list<PeSistemaParticulas*> sistemasParticulas = pMundo_->getSistemasParticulas();
	list<PeSistemaParticulas*>::iterator sPIt = sistemasParticulas.begin();

	while (sPIt != sistemasParticulas.end())
	{
		sP = *sPIt;
		//collisionCheck = ps->GetCollisionCheckActive();
		
		list<PeParticula*> particulas = sP->getParticulas();
		list<PeParticula*>::iterator pIt = particulas.begin();

		while (pIt != particulas.end())

		{
			
			gravForce = vec3Multiply (pMundo_->getGravedad(), p->masa_);
			//simulamos la particula
			p->AddFuerza(vec3Add (ForceAc, gravForce));
			if (sP->SimulaPasoParticula(p, deltaTime)){
				//si la particula sigue viva miramos si colisiona
				/*if (collisionCheck && pCollEngine->CheckParticleCollision(p))
					ps->ParticleCollisionEvent(p, j);*/
				pIt++;
			}
			else{
				//En teoría al borrar no hace falta aumentar el iterador.
				particulas.erase(pIt);
			}
			
		}
		//quitamos sistemas de particulas muertos
		if (sP->getNumParticulas() <= 0)
		{
			sistemasParticulas.erase(sPIt);
		}
		else{

			sPIt++;
		}
	}
}