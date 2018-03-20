#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../cplx/cplx.h"
#include "../mytestPlatform.h"

int mytest_Spannung_main(void)
{
	double f_Hz, f_start_Hz, f_end_Hz, f_factor, w, H_dB, R1, R2, L, C;
	cplx_t ZL, ZC, Z1, Z2, H;

	f_start_Hz = 50;
	f_end_Hz = 5000;
	f_factor = 1.1;  /* logarithmische Frequenzskala... */
	R1 = 1e4;
	R2 = 1;
	C = 25.3e-6;
	L = 1e-3;

	printf("f / Hz  H                                               H_dB\n");
	printf("------------------------------------------------------------\n");
	for (f_Hz = f_start_Hz; f_Hz <= f_end_Hz; f_Hz *= f_factor)
	{
		w = 2.0*my_PI*f_Hz;      /* Kreisfrequenz */
		ZL.re = 0.0;
		ZL.im = w*L;             /* kompl. Widerstand Spule */
		ZC.re = 0.0;
		ZC.im = -1.0 / (w*C);      /* kompl. Widerstand Kondensator */

		Z1.re = R1;
		Z1.im = 0.0;             /* Hilfsgroesse */
		Z2.re = R2;
		Z2.im = 0.0;
		Z2 = c_add(c_add(Z2, ZL), ZC); /* R2,L,C in Reihe */

		H = c_div(Z2, c_add(Z1, Z2));
		H_dB = 20 * log10(betrag(H));

		printf("%.1lf\t", f_Hz);
		c_print_polar_grad(H);
		printf("\t");
		printf("%.1lf", H_dB);
		printf("\n");
	}

	getchar();

	return 0;
}
