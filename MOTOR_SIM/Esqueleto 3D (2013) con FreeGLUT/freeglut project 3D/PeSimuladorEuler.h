#ifndef	 PESIMULADOREULER
#define  PESIMULADOREULER

#include "PeSimulador.h"

class PeSimuladorEuler :
	public PeSimulador
{
public:
	PeSimuladorEuler(PeMundo* pMundo);
	virtual ~PeSimuladorEuler();

	virtual void Simular(float deltaTime);
	

private:

	vec3 ForceAc;
	void SimulaParticulas(float deltaTime);
	/*void SimulateBodies(real DeltaTime);
	void ComputeForcesBodies(int ConfigurationIndex);
	void IntegrateBodies(real DeltaTime);*/

};


#endif