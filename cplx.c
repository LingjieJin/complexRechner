//
//  cplx.c
//  complexRechner
//
//  Created by kIng_martin on 2018/3/2.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include "cplx.h"
#include <math.h>

cplx_t Eingeben()
{
    cplx_t retval;
    double a,b;
    
    printf("bitte zwei num geben");
    scanf("%lf",&a);
    fflush(stdin);
    scanf("%lf",&b);
    fflush(stdin);
    
    retval.re = a;
    retval.im = b;
    
    return retval;
}

void Ausgeben(cplx_t a)
{
    printf("%.4lf+%.4lf\n" , a.re, a.im);
    
}

double real(cplx_t a)
{
    return  a.re;
}

double imag(cplx_t a)
{
    return a.im;
}

double betrag(cplx_t a)
{
    return sqrt(a.re*a.re+a.im*a.im);
}

cplx_t cadd(cplx_t z1, cplx_t z2)
{
    cplx_t retval;
    retval.re = z1.re + z2.re;
    retval.im = z1.im + z2.im;
    
    return retval;
}
cplx_t csub(cplx_t z1, cplx_t z2)
{
    cplx_t retval;
    retval.re = z1.re - z2.re;
    retval.im = z1.im - z2.im;
    
    return retval;
}
cplx_t cmult(cplx_t z1, cplx_t z2)
{
    cplx_t retval;
    retval.re = z1.re * z2.re - z1.im * z2.im;
    retval.im = z1.re * z2.im + z2.re * z1.im;
    
    return retval;
}
cplx_t cdiv(cplx_t z1, cplx_t z2)
{
    cplx_t retval;
    retval.re = (z1.re * z2.re + z1.im * z2.im)/
        (z2.re * z2.re + z2.im * z2.im);
    retval.im = (z2.re * z1.im - z1.re * z2.im)/
        (z2.re * z2.re + z2.im * z2.im);
    
    return retval;
}
double cplxexp(cplx_t z)
{
    double retval;
    retval = exp(z.re)*(cos(z.im)+sin(z.im));
    
    return retval;
}




