//
//  main.c
//  Shell Sort
//
//  Created by Surface Laptop 2 on 2019/8/4.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

void shell_sort( int arr[], int len )
{
    int gap, i, j;
    int temp;
    for( gap = len >> 1; gap > 0; gap = gap >> 1 )
        for( i = gap; i < len; i++ ){
            temp = arr[i];
            for( j = i - gap; j >= 0 && arr[j] > temp; j = j - gap )
                arr[j + gap]= arr[j];
            arr[j + gap] = temp;
        }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 22, 34, 3, 83, 55, 80, 20, 36, 5, 64, 67, 9, 54 };
    int len = ( int ) sizeof( arr ) / sizeof( * arr );
    shell_sort( arr, len );
    int i;
    for( i = 0; i < len; i++ )
        printf( "%d ", arr[i] );
    return 0;
}
