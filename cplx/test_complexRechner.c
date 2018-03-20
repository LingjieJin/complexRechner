#include <stdlib.h>
#include <stdio.h>
#include "cplx.h"
#include "mytestPlatform.h"


int mytest_cplx_main(void)
{
	cplx_t z1, z2, z3;

	z1 = c_input_kart();
	z2 = c_input_kart();

	c_print_kart(z1);
	c_print_polar_grad(z1);
	printf("\n");
	c_print_kart(z2);
	c_print_polar_grad(z2);
	printf("\nAddition:\t\t");

	z3 = c_add(z1, z2);
	c_print_kart(z3);
	printf("\nSubtraktion:\t\t");

	z3 = c_sub(z1, z2);
	c_print_kart(z3);
	printf("\nMultiplikation:\t\t");

	z3 = c_mult(z1, z2);
	c_print_kart(z3);
	printf("\nDivision:\t\t");

	z3 = c_div(z1, z2);
	c_print_kart(z3);
	printf("\n");

	/* hier fehlt noch der Testcode fuer die anderen Modulfunktionen... */

	getchar();

	system("PAUSE");
	return 0;
}
