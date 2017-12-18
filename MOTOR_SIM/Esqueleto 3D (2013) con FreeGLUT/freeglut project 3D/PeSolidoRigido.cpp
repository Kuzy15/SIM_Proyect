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
	//Actualizamos el estado
	rb_->update(dT);
	//Actualizamos la matriz de OpenGl
	for (size_t i = 0; i < 4; i++){
		for (size_t j = 0; j < 4; j++){
		ob_->getMatriz()->getM()[4 * i + j] = rb_->getMfin()[i][j];
		}
	}

}

void PeSolidoRigido::dibuja(){
	
	
	
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