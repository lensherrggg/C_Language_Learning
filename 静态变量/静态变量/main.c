//
//  main.c
//  静态变量
//
//  Created by Surface Laptop 2 on 2019/8/5.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

void fun()
{
    int i = 0;
    static int static_i = 0;
    printf( "i = %d\n", i );
    printf( "static_i = %d\n", static_i);
    i++;
    static_i++;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    for( int i = 0; i < 3; i++ )
        fun();
    return 0;
}
