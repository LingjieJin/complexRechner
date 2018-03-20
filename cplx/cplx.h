#ifndef _cplx_h_
#define _cplx_h_

#define my_PI 3.1415926

typedef struct{
	double re;
	double im;
}cplx_t;

cplx_t eingeben_kart(void);
void c_print_kart(cplx_t z);

void c_print_polar(cplx_t z);
void c_print_polar_grad(cplx_t z);
cplx_t c_input_kart(void);
cplx_t c_input_polar(void);

cplx_t Eingeben(void);
void Ausgeben(cplx_t z);

double real(cplx_t z);
double image(cplx_t z);
double betrag(cplx_t z);
double phase(cplx_t z);

cplx_t c_add(cplx_t z1, cplx_t z2);
cplx_t c_sub(cplx_t z1, cplx_t z2);
cplx_t c_mult(cplx_t z1, cplx_t z2);
cplx_t c_div(cplx_t z1, cplx_t z2);
cplx_t c_exp(cplx_t z);
cplx_t c_sqart(cplx_t z);

#endif // cplx_h
