#include "PeFuerza.h"


PeFuerza::PeFuerza(){ dir_ = vec3Zero(); }

PeFuerza::PeFuerza(vec3 f)
{
	dir_ = f;
}


PeFuerza::~PeFuerza()
{
}

void PeFuerza::setDir(vec3 d){ dir_ = d; }