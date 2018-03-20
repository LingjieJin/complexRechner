#include <stdio.h>

#include "digitalFilter.h"

double BP_Filter01(double x)
{
    /* y(n) = D0(x(n-2) - x(n)) - C0*y(n-2) - C1*y(n-1) */
    static double x_1=0, x_2=0, y_1=0, y_2=0;
    double y;
    /* double D0=-0.363323,  C0=0.818339, C1=1.744683; */
    double D0=-0.031348,  C0=0.984326, C1=-1.983834;

    y = D0 *  (x_2 - x) - C0* y_2 - C1 *  y_1;
    x_2 = x_1;
    x_1 = x;
    y_2 = y_1;
    y_1 = y;

    return y;

}

int SaveArray(double *a, int n, char *DateiName)
{
    FILE *fp;
    int k;
    if(NULL == (fp = fopen(DateiName,"wt")))
        return -1;
    for(k = 0; k < n; k++)
    {
        fprintf(fp,"%lf\n", a[k]);
    }
    fclose(fp);

    return 0;
}

int LoadArray(double *a, int n, char *DateiName)
{
    FILE *fp;
    int k;
    if(NULL == (fp = fopen(DateiName,"rt")))
        return -1;
    for(k = 0;k<n;k++)
    {
        fscanf(fp,"%lf", &a[k]);
    }
    fclose(fp);

    return 0;
}

double analy(double x, double a)
{
    /* y(n) = (1-a)*x(n) + a*y(n-1) */
    static double y_1=0;
    double y;

    y = (1-a) * x + a * y_1;
    y_1 = y;

    return y;
}
