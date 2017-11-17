#ifndef PEFUERZA_H
#define PEFUERZA_H

#include "ccVector.h"

const vec3 G = { 0, -9.8, 0 };


class PeFuerza
{
private:
	
	vec3 dir_;

public:
	PeFuerza(vec3 f);
	virtual ~PeFuerza();

	//virtual vec3 GetFuerza() = 0;


	inline vec3 GetDirectionVector(){ return dir_; };
};
#endif
