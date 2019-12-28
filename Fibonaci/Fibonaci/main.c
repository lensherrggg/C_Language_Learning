//
//  main.c
//  Fibonaci
//
//  Created by Surface Laptop 2 on 2019/8/3.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

int Fibonaci( int i )
{
    if( i == 0 )
        return 0;
    else if(i == 1 )
        return 1;
    else
        return Fibonaci( i - 1 ) + Fibonaci( i - 2 );
}

int main()
{
    int i;
    for( i = 1; i <= 10; i++ )
    {
        printf("Fibonaci( %d ) = %d\n", i, Fibonaci(i));
    }
    return 0;
}
