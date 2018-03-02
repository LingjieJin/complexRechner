//
//  cplx.h
//  complexRechner
//
//  Created by kIng_martin on 2018/3/2.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#ifndef cplx_h
#define cplx_h

typedef struct{
    double re;
    double im;
}cplx_t;

cplx_t Eingeben(void);
void Ausgeben(cplx_t a);
double real(cplx_t a);
double imag(cplx_t a);
double betrag(cplx_t a);
cplx_t cadd(cplx_t z1, cplx_t z2);
cplx_t csub(cplx_t z1, cplx_t z2);
cplx_t cmult(cplx_t z1, cplx_t z2);
cplx_t cdiv(cplx_t z1, cplx_t z2);
double cplxexp(cplx_t z);


#endif /* cplx_h */
