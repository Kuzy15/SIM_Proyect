#pragma once
#include "PeSistemaParticulas.h"
class PeSPHumo :
	public PeSistemaParticulas
{
public:
	PeSPHumo(vec3 origen, int maxParticulas, float vida, float kvd);
	virtual ~PeSPHumo();
	virtual bool SimulaPasoParticula(PeParticula*p, vec3  a, float deltaTime);
	virtual bool SimulaPasoParticula(PeParticula*p, float deltaTime);
	virtual void addFuerza(vec3 f);
	void creaPalmera(vec3 ignicion);
private:
	PeParticula* cohete;
	bool needExplo;
};

