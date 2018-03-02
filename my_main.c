//
//  my_main.c
//  complexRechner
//
//  Created by kIng_martin on 2018/3/2.
//  Copyright © 2018年 kIng_martin. All rights reserved.
//

#include <stdio.h>
#include "cplx.h"

int main()
{
    cplx_t a1, a2;
    a1 = Eingeben();
    Ausgeben(a1);
    a2 = Eingeben();
    Ausgeben(a2);
    
    Ausgeben(cadd(a1, a2));
    
    getchar();
    return 0;
}
