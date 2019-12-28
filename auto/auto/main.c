//
//  main.c
//  auto
//
//  Created by Surface Laptop 2 on 2019/8/5.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i, num;
    num = 2;
    for( i = 0; i < 3; i++ )
    {
        printf( "num = %d\n", num );
        num++;
        {
            auto int num = 1;
            printf( "内置模块num = %d\n", num );
            num++;
        }
    }
    return 0;
}
