#ifndef PESIMULADOR_H
#define PESIMULADOR_H

#include "PeMundo.h"

class PeSimulador
{
public:
	PeSimulador(PeMundo* pMundo);
	virtual ~PeSimulador();

	virtual void Simular(float deltaTime) = 0;
	inline void SetMaxTiempoPaso(float d){ maxTiempoPaso_ = d; };
	/*inline void SetDep(float d){ MaxTimeStep = d; };
	inline void SetDepthEpsilon(float d){ pCollEngine->SetDepthEpsilon(d); };
	inline void SetParticleDepthEpsilon(float d){ pCollEngine->SetParticleDepthEpsilon(d); };*/

protected:

	PeMundo* pMundo_;
	//CCollisionEngine * pCollEngine;
	float maxTiempoPaso_;
	float lastTime_;
	//void CalculateVertices(int ConfigurationIndex);
};

#endif