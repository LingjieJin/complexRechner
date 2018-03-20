#include <math.h>
#include "cplx.h"
#include "mytestPlatform.h"

int my_spannung_main(void)
{
	double R1 = 1e4, R2 = 1.0, L = 1e-3, C = 25.3e-6;

	double f_start_Hz = 50, f_end_Hz = 5000, f_factor = 1.1; /* logarithmische Frequenzskala... */

	double w = 0.0;
	double auswert;
	cplx_t z1, z2 ;

	printf("f/Hz\t\t20*log10(|H(f)|)\n____________________\n");

	for (; f_start_Hz <= f_end_Hz; f_start_Hz*=f_factor)
	{
		w = 2 * my_PI * f_start_Hz;

		z1.re = R1;
		z1.im = 0;
		z2.re = R2;
		z2.im = w * L + 1 / (w * C);
		
		auswert = 20 * log10(betrag(c_div(z2, c_add(z1, z2))));

		printf("%.1lf\t\t%.1lf\n", f_start_Hz, auswert);
	}

	getchar();

	return 0;
}