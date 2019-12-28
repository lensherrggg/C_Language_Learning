//
//  main.c
//  内存管理
//
//  Created by Surface Laptop 2 on 2019/8/3.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char name[100];
    char * description;
    
    strcpy( name, "Zara Ali");
    
    /*动态分配内存*/
    description = ( char * )malloc( 200 * sizeof( char));
    if( description == NULL )
    {
        fprintf( stderr, "Error - unable to allocate required memory.\n" );
    }
    else
    {
        strcpy( description, "Zara Ali a DPS student in class 10th\n" );
    }
    printf( "Name = %s\n", name );
    printf( "Description: %s\n", description );
}
