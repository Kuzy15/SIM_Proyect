#include "PeSimulador.h"


PeSimulador::PeSimulador(PeMundo* pMundo)
{
	pMundo_ = pMundo;
	//pCollEngine = new CCollisionEngine(pWorld);
	lastTime_ = 0;
	maxTiempoPaso_ = 0.03125;//valor por defecto

	// calculate initial bounding volume positions
	/*CalculateVertices(0);
	CalculateVertices(1);*/
	
}



PeSimulador::~PeSimulador()
{
}
