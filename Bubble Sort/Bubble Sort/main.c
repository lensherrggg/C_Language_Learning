//
//  main.c
//  Bubble Sort
//
//  Created by Surface Laptop 2 on 2019/8/3.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

void bubble_sort( int arr[], int len )
{
    int i, j, temp;
    for( i = 0; i < len - 1; i++ )
        for( j = 0; j < len - 1; j++ )
            if( arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    // insert code here...
    int arr[] = { 22, 34, 3, 83, 55, 80, 20, 36, 5, 64, 67, 9, 54 };
    int len = ( int ) sizeof( arr ) / sizeof( * arr );
    bubble_sort( arr, len );
    int i;
    for( i = 0; i < len; i++ )
        printf( "%d ", arr[i] );
    return 0;
}
