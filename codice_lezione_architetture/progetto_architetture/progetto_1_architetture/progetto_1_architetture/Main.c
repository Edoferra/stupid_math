/*! @file Main.c
	@brief Library of function for computing integrals
	@autor Edoardo Ferrari

	Details.

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


int main() {

	/* setting all the parameters */
	float fcoeff[4] = { -10.0,1.0,0.0,2.0 };	/* the polynomial */
	float xmin = 0.0; 						/* the intervallo integrazione */
	float xmax = 5.0;
	int intervals = 500; 					/* number of equally spaced intervals */


	float integ1, integ2;

	int i;
	float in = xmin;
	float gap = (xmax - xmin) / (float)intervals;
	float* fvalues = NULL;

	/* this array will store the (steps+1) values of the polynomial that are delimiting the equally spaced intervals*/
	fvalues = (float*)malloc(sizeof(float) * (intervals + 1));
	if (fvalues == NULL) {
		printf("\nERROR: cannot allocate memory\n"); /* divido lo spazio integrazione */
		exit(-1);
	}

	/* to get the value of the polynomial at the different points that are delimiting the intervals */
	for (i = 0; i <= intervals; i++) {
		fvalues[i] = Polynomial(fcoeff, 4, in);
		in += gap;
	}

	integ1 = 0.;
	integ2 = 0.;

	/* to compute the integral according to the rectangular rule */
	Rectangular(fvalues, intervals + 1, gap, &integ1, &integ2);
	printf("\nRectangular rule - The integral between %f and %f is in the interval: [%f,%f]\n", xmin, xmax, integ1, integ2);

	/* to compute the integral according to the trapezoidal rule */
	integ1 = Trapezoidal(fvalues, intervals + 1, gap);
	printf("\nTrapezoidal rule - The integral between %f and %f is : %f\n", xmin, xmax, integ1);

	/* deallocation dell'array */
	if (fvalues != NULL)
		free(fvalues);

	return 0;
}