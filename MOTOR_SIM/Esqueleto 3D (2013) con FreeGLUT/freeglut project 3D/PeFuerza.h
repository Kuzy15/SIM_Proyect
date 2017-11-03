#ifndef PEFUERZA_H
#define PEFUERZA_H

#include "ccVector.h"

class PeFuerza
{
private:
	
	vec3 dir_;

public:
	PeFuerza();
	virtual ~PeFuerza();

	virtual vec3 GetFuerza() = 0;


	inline vec3 GetDirectionVector(){ return dir_; };
};
#endif
