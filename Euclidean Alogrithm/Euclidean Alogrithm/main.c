//
//  main.c
//  Euclidean Alogrithm
//
//  Created by Surface Laptop 2 on 2019/8/4.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

/*
int gcd( int n1, int n2 )
{
    int r;
    while( n1 % n2 != 0)
    {
        r = n1 % n2;
        n1 = n2;
        n2 = r;
    }
    return n2;
}
 */

int gcd( int n1, int n2 )
{
    if( n1 % n2 == 0 )
        return n2;
    else
        return gcd( n2, n1 % n2 );
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n1, n2;
    printf( "The first number: \n" );
    scanf( "%d", &n1);
    printf( "The second number: \n" );
    scanf( "%d", &n2);
    
    printf( "%d\n", gcd( n1, n2 ));
    
    return 0;
}
