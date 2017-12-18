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
	
	
	
}

void PeSolidoRigido::dibuja(){
	
	ob_->getMatriz()->traslada(rb_->getPos().x, rb_->getPos().y, rb_->getPos().z);

	//std::cout << rb_->getPos().x << rb_->getPos().y << rb_->getPos().z << "-----";
	ob_->getMatriz()->rota(rb_->getR());
	ob_->dibuja();
	ob_->getMatriz()->reset();
}

void PeSolidoRigido::setGravedad(bool g){

	if (g){
		rb_->addForce(rb_->FG_);
	}
	else{
		rb_->addForce(vec3Negate(rb_->FG_));
	}
}