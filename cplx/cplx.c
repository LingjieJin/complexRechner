#include "cplx.h"
#include <math.h>
#include <stdio.h>

void c_print_kart(cplx_t z)
{
	printf("%.4lf|%.4lf \n", z.re, z.im);
}

cplx_t eingeben_kart(void)
{
	cplx_t retval;

	printf("2 double geben!\n");
	printf("re:\n");
	fflush(stdin);
	//scanf("%lf", &retval.re);
	printf("im:\n");
	fflush(stdin);
	//scanf("%lf", &retval.im);

	return retval;
}

void c_print_polar(cplx_t z)
{
	printf("modulus:%lf angele:%lf rad \n", betrag(z), phase(z));
}

void c_print_polar_grad(cplx_t z)
{
	printf("modulus:%lf angle:%lf Grad \n", betrag(z), phase(z) / my_PI*180.0);
}

cplx_t c_input_kart(void)
{
	cplx_t retval;

	printf("Realteil: ");
	scanf("%lf", &retval.re);
	printf("Imaginaerteil: ");
	scanf("%lf", &retval.im);

	return retval;
}

cplx_t c_input_polar(void)
{
	cplx_t retval;
	double mode, phi_grad, phi_rad;

	printf("Betrag: ");
	scanf("%lf", &mode);
	printf("Winkel in Grad: ");
	scanf("%lf", &phi_grad);
	phi_rad = phi_grad / 180.0 * my_PI;
	retval.re = mode * cos(phi_rad);
	retval.im = mode * sin(phi_rad);

	return retval;
}

cplx_t Eingeben()
{
	cplx_t retval;

	printf("bitte zwei num geben \n real:");
	scanf("%lf", &retval.re);
	//fflush(stdin);
	printf("image:");
	scanf("%lf", &retval.im);
	//fflush(stdin);

	return retval;
}

void Ausgeben(cplx_t z)
{
	printf("%lf+%lfI\n", z.re, z.im);
}

double real(cplx_t z)
{
	return  z.re;
}

double image(cplx_t z)
{
	return z.im;
}

double betrag(cplx_t z)
{
	double retval;

	retval = sqrt(z.re * z.re + z.im * z.im);

	return  retval;
}

double phase(cplx_t z)
{
	double phi;

	if (z.re == 0.0)
	{
		if (z.im == 0.0)
		{
			phi = 0.0;
		}
		else
		{
			if (z.im > 0) phi = my_PI / 2.0;
			else          phi = -my_PI / 2.0;
		}
	}
	else
	{
		phi = atan2(z.im, z.re);
	}
	/* transform from -pi..pi to 0..2pi: */
	if (phi<0)
	{
		phi = 2 * my_PI + phi;
	}

	return phi;
}

cplx_t c_add(cplx_t z1, cplx_t z2)
{
	cplx_t retval;

	retval.re = z1.re + z2.re;
	retval.im = z1.im + z2.im;

	return retval;
}
cplx_t c_sub(cplx_t z1, cplx_t z2)
{
	cplx_t retval;
	retval.re = z1.re - z2.re;
	retval.im = z1.im - z2.im;

	return retval;
}
cplx_t c_mult(cplx_t z1, cplx_t z2)
{
	cplx_t retval;

	retval.re = z1.re * z2.re - z1.im * z2.im;
	retval.im = z1.re * z2.im + z2.re * z1.im;

	return retval;
}

cplx_t c_div(cplx_t z1, cplx_t z2)
{
	cplx_t retval;
	double mode;

	mode = z2.re * z2.re + z2.im * z2.im;
	retval.re = (z1.re * z2.re + z1.im * z2.im) / mode;
	retval.im = (z2.re * z1.im - z1.re * z2.im) / mode;

	return retval;
}

cplx_t c_exp(cplx_t z)
{
	cplx_t retval;

	retval.re = exp(z.re)*cos(z.im);
	retval.im = exp(z.re)*sin(z.im);

	return retval;
}

cplx_t c_sqrt(cplx_t z)
{
	cplx_t retval;

	retval.re = sqrt(betrag(z)) + cos(phase(z) / 2.0);
	retval.im = sqrt(betrag(z)) + sin(phase(z) / 2.0);

	return retval;
}
