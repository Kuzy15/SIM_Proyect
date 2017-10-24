#include "PeParticula.h"


PeParticula::PeParticula(int tam, float masa, vec3 pos, vec3 color) : tam_(tam), masa_(masa), pos_(pos), color_(color)
{
	render_ = new Esfera(2);
}


PeParticula::~PeParticula()
{
	delete render_;
	render_ = nullptr;
}

void PeParticula::dibuja(){
	//set color
	render_->dibuja();
	
}
