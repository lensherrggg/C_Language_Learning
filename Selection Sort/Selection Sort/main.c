//
//  main.c
//  Selection Sort
//
//  Created by Surface Laptop 2 on 2019/8/3.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

void swap( int *a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort( int arr[], int len )
{
    int i, j;
    for( i = 0; i < len - 1; i++ )
    {
        int min = i;
        for( j = i + 1; j < len; j++ )
            if ( arr[j] < arr[min] )
                min = j;
        swap( &arr[min], &arr[i] );
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 22, 34, 3, 83, 55, 80, 20, 36, 5, 64, 67, 9, 54 };
    int len = ( int ) sizeof( arr ) / sizeof( * arr );
    selection_sort( arr, len );
    int i;
    for( i = 0; i < len; i++ )
        printf( "%d ", arr[i] );
    return 0;
}
