#include <stdio.h>
#include <math.h>

#include "digitalFilter.h"
#include "../mytestPlatform.h"

#define N 5000

int mytest_digitalFilter_main(void)
{   double x[N], y[N];
    int i;

    for(i=0; i<N; i++)
    {
        x[i] = 0;
    }

    /* Impulsantwort: */
    x[0] = 1.0;
    for(i=0; i<N; i++)
    {
        y[i] = BP_Filter01(x[i]);
    }
    if(0!=SaveArray(x, N, "impuls.txt"))
        puts("error in SaveArray");
    if(0!=SaveArray(y, N, "impulsantwort.txt"))
        puts("error in SaveArray");

    /* Sprungantwort */
    for(i=0; i<N/2; i++)
    {
        x[i] = 0;
    }
    for(i=N/2; i<N; i++)
    {
        x[i] = 1;
    }
    for(i=0; i<N; i++)
    {
        y[i] = BP_Filter01(x[i]);
    }
    if(0!=SaveArray(x, N, "sprung.txt"))
        puts("error in SaveArray");
    if(0!=SaveArray(y, N, "sprungantwort.txt"))
        puts("error in SaveArray");

    return 0;
}
