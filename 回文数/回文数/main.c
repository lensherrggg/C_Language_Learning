//
//  main.c
//  回文数
//
//  Created by Surface Laptop 2 on 2019/8/4.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int originalInteger, reversedInteger = 0, remainder = 0, n;
    printf( "Input the original integer: " );
    scanf( "%d", &n );
    originalInteger = n;
    
    while( n != 0 )
    {
        remainder = n % 10;
        reversedInteger = reversedInteger * 10 + remainder;
        n = n / 10;
    }
    
    if( reversedInteger == originalInteger )
        printf( "Yes" );
    else
        printf( "No" );
    
    return 0;
}
