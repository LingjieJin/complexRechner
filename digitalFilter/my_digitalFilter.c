#include <stdio>

#include "digitalFilter.h"
#include "../mytestPlatform.h"

#define AbtastNum 2000

int my_digitalFilter_main(void)
{
    double a[AbtastNum],b[AbtastNum];
    int i;

    /* Impul init */
    for(i = 0; i<AbtastNum;i++)
    {
        a[i] = 0;
    }
    a[0] = 1;
    for(i = 0; i<AbtastNum;i++)
    {
        //b[i] = BP_Filter01(a[i]);
        b[i] = TP_Filter(a[i]);
    }

    /* Impul/ -antwort Speichrn */
    //SaveArray(a, AbtastNum, "my_impul.txt");
    //SaveArray(b, AbtastNum, "my_impulsantwort.txt");

    SaveArray(a, AbtastNum, "my_TP_impul.txt");
    SaveArray(b, AbtastNum, "my_TP_impulsantwort.txt");

    /* Sprung init */
    for(i = 0; i<AbtastNum;i++)
    {
        a[i] = 1;
    }
    for(i = 0; i<AbtastNum;i++)
    {
        b[i] = TP_Filter(a[i]);
    }

    /* Impul/ -antwort Speichrn */
    //SaveArray(a, AbtastNum, "my_sprung.txt");
    //SaveArray(b, AbtastNum, "my_sprungantwort.txt");

    SaveArray(a, AbtastNum, "my_TP_sprung.txt");
    SaveArray(b, AbtastNum, "my_TP_sprungantwort.txt");

    return 0;


}
