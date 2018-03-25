#include <stdio.h>
#include <stdlib.h>
#include "snd_lib/snd_lib.h"

#include "../mytestPlatform.h"

#define N 2048

int mytest_wav_main(void)
{
    SndDevice_t *psd;
    short buf[N];
    int j;

    psd = sndOpen(SND_READ_WRITE, SND_STEREO);

    for(j=0; j<500; j++)
    {
        printf("loop counter:%d\n", j);
        if(N != sndRead(psd, buf, N))
        {   printf("win_sndRead crashed...");
        }
        if(N != sndWrite(psd, buf, N))
        {   printf("sndWrite crashed...");
        }
    }
    psd = sndClose(psd);
    return 0;
}
