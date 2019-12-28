//
//  main.c
//  递归
//
//  Created by Surface Laptop 2 on 2019/8/3.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

double factorial( unsigned int i )
{
    if( i <= 1 )
    {
        return 1;
    }
    return i * factorial( i - 1 );
}

int main()
{
    int i = 15;
    printf("%d 的阶乘为 %f\n", i, factorial(i));
}
