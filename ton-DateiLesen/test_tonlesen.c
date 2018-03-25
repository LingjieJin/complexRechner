/*  lesen von ton-Dateien
    'ton' ist ein fiktives Dateiformat für Audio.
    Aufbau des Dateikopfes 'ton-Datei'
    Nr.Bytes  Bytes  Bezeichnung    Kommentar
    0-3       4      type           String ''ton'' mit '\0'
    4-7       4      length         Gesamtlänge der Datei in Bytes
    8-11      4      nSamplesPerSec Abtastfrequenz in Hz
    ------------------------------------------------------
    12-13     2      data (short)   Abtastwert x(0)
    14-15     2      data (short)   Abtastwert x(1)
    ...
Abtastwerte sind mono und vom Typ short, -32768...32767, ''Ruhe'' = 0

Erzeugte 'ton'-Datei unter Windows mit bcc32-Compiler (ggf. wichtig
für das memory alignment). Sinus-Signal mit wählbarer Frequenz.
*/

#include<stdio.h>
#include<string.h>

typedef struct
{   char    type[4];
    unsigned long length;
    unsigned long nSamplesPerSec;
} Ton_header_t;

#define NSTRING 128

int mytest_tondatei_main(void)
{   FILE *fp;
    char fileName[NSTRING];
    Ton_header_t th={0};
    int retval;

    puts("Lesen von Dateien im fikitven 'ton'-Format");
    printf("Name der zu lesenden Datei:");
    fflush(stdin);
    scanf("%s",fileName);
    /*printf("fileName:%s len:%d\n", fileName, strlen(fileName)); */
    fp=fopen(fileName,"rb");
    if(fp==NULL)
    {   printf("FEHLER: kann Datei %s nicht oeffnen...", fileName);
        return -1;
    }
    printf("\nKopf lesen...\n");
    if(1!=(retval=fread(&th,sizeof(Ton_header_t),1,fp)))
    {   printf("FEHLER: kann Datei nicht lesen, retval=%d\n", retval);
        fclose(fp);
        return -1;
    }
    printf("type:%s \nDateilaenge:%d \nAbtastfrequnz:%d\n\n",
           th.type, th.length, th.nSamplesPerSec);
    puts("weiter mit ENTER...");
    fflush(stdin);
    getchar();
    { int i=0;
      short x;

      do
      { if(1==fread(&x,sizeof(short),1,fp))
        {   printf("i=%d x=%d\n", i++, x);
        }
      } while(!feof(fp));
    }
    fclose(fp);
    printf("...done!\n");
    return 0;
}
