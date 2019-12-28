//
//  main.c
//  约瑟夫生存者游戏
//
//  Created by Surface Laptop 2 on 2019/8/4.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i = 0; //编号
    int c = 0; //报数
    int count = 0; //下船人数
    int a[10] = {0}; //记录是否在船上
    while( 1 )
    {
        if( i == 10 )
            i = 0;
        if( a[i] == 0 )
            c = c + 1;
        if( c == 5 )
        {
            count = count + 1;
            a[i] = 1;
            printf( "第%d号下船了\n", i + 1 );
            c = 0;
        }
        if( count == 5 )
            break;
        i = i + 1;
    }
    
    return 0;
}
