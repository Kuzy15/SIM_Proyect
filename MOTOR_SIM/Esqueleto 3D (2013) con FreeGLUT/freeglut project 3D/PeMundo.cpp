#include "PeMundo.h"


PeMundo::PeMundo()
{
	sistemasParticulas_.push_back(new PeSistemaParticulas());
}


PeMundo::~PeMundo()
{
}

void PeMundo::dibuja(){

	sistemasParticulas_.front()->dibuja();
}