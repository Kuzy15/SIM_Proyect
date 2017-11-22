#include "PeSolidoRigido.h"


PeSolidoRigido::PeSolidoRigido()
{
}


PeSolidoRigido::~PeSolidoRigido()
{
}

void PeSolidoRigido::update(const float &dT){

	rb_->update(dT);
}

void PeSolidoRigido::dibuja(){

	ob_->dibuja();
}
