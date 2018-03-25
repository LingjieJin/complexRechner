#include <stdio.h>
#include <stdlib.h>

#include "../mytestPlatform.h"

typedef struct tonHeader
{
    char datei[4];
    unsigned long length;
    unsigned long nSamplesPerSec;
}ton_Header_t;

int my_ton_Datei_lesen_main(void)
{
    char inhalt[100];
    FILE *fp;

    fp = fopen("sin_440.ton","r");
    if(fp==NULL)
    {
        printf("FEHLER: kann Datei  nicht oeffnen...");
        return -1;
    }
    //fread(inhalt,sizeof(char),1,fp);
    fscanf(fp,inhalt);


    fclose(fp);

    printf("%c%c%c%c",inhalt[0],inhalt[1],inhalt[2],inhalt[3]);

    return 0;
}
