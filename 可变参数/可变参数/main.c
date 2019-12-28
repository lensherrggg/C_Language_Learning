//
//  main.c
//  可变参数
//
//  Created by Surface Laptop 2 on 2019/8/3.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>

double average( int num, ... )
{
    va_list valist;
    double sum = 0.0;
    int i;
    
    /*为num个参数初始化valist*/
    va_start( valist, num );
    
    /*访问所有赋给valist的参数*/
    for( i = 0; i < num; i++ )
    {
        sum = sum + va_arg( valist, int );
    }
    
    /*清理为valist保留的内存*/
    va_end( valist );
    
    return sum / num;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf( "The average of 2, 3, 4, 5 is %f\n", average( 4, 2, 3, 4, 5));
    return 0;
}
