//
//  main.c
//  Insertion Sort
//
//  Created by Surface Laptop 2 on 2019/8/4.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

void insertion_sort( int arr[], int len )
{
    int i, j, temp;
    for( i = 1; i < len; i++ )
    {
        temp = arr[i] ;
        for( j = i; j > 0 && temp < arr[j-1]; j-- )
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 22, 34, 3, 83, 55, 80, 20, 36, 5, 64, 67, 9, 54 };
    int len = ( int ) sizeof( arr ) / sizeof( * arr );
    insertion_sort( arr, len );
    int i;
    for( i = 0; i < len; i++ )
        printf( "%d ", arr[i] );
    return 0;
}
