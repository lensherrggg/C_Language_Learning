//
//  main.c
//  external
//
//  Created by Surface Laptop 2 on 2019/8/5.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

int a, b, c;

void add()
{
    int a = 3;
    c = a + b;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    a = 4;
    b = 4;
    add();
    printf( "c = %d\n", c );
    
    return 0;
}
