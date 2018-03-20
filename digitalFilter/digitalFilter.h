#ifndef _digitalFilter_h_
#define _digitalFilter_h_

#include <stdio.h>
#include <math.h>

double BP_Filter01(double x);
int SaveArray(double *a, int n, char *DateiName);
int LoadArray(double *a, int n, char *DateiName);

double analy(double x,double a);

#endif // _digitalFilter_h_
