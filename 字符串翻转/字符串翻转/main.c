//
//  main.c
//  字符串翻转
//
//  Created by Surface Laptop 2 on 2019/8/4.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

void reverseString( )
{
    char c;
    scanf( "%c", &c );
    if( c != '\n' )
    {
        reverseString();
        printf( "%c", c );
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Input string: ");
    reverseString();
    
    return 0;
}
