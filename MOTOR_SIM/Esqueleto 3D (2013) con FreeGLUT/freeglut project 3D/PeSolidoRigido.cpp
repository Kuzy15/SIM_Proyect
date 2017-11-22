#include "PeSolidoRigido.h"


PeSolidoRigido::PeSolidoRigido()
{
	
	
}


PeSolidoRigido::~PeSolidoRigido()
{
	delete rb_; rb_ = nullptr;
	delete ob_; ob_ = nullptr;
}

void PeSolidoRigido::update(const float &dT){

	rb_->update(dT);
	
	ob_->getMatriz()->traslada(rb_->getPos().x, rb_->getPos().y, rb_->getPos().z);
	
}

void PeSolidoRigido::dibuja(){

	ob_->dibuja();
}

void PeSolidoRigido::setGravedad(bool g){

	if (g){
		rb_->addForce(rb_->FG_);
	}
	else{
		rb_->addForce(vec3Negate(rb_->FG_));
	}
}