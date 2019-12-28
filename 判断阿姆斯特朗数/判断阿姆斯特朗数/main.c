//
//  main.c
//  判断阿姆斯特朗数
//
//  Created by Surface Laptop 2 on 2019/8/4.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int originalNumber, result = 0, n, remainder = 0;
    
    printf( "Input the original number: ");
    scanf( "%d", &n );
    originalNumber = n;
    
    while( n != 0)
    {
        remainder = n % 10;
        result = result + remainder * remainder * remainder;
        n = n / 10;
    }
    
    if ( result == originalNumber )
        printf( "yes" );
    else
        printf( "no" );
    
    return 0;
}
