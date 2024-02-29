/*! @file mathf.h
	@brief Library of function for computing integrals
	@autor Edoardo Ferrari

	Details.

*/


#ifndef MATHF_H
#define MATHF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float Polynomial(float* coeff, int size, float in);
void Rectangular(float* values, int size, float stepsize, float* integ1, float* integ2);
float Trapezoidal(float* values, int size, float stepsize);



#endif
