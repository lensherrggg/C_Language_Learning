//
//  main.c
//  链表
//
//  Created by Surface Laptop 2 on 2019/8/5.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data; //存放节点数据
    struct Node *next; //指向下一个节点
}Node, *PNode;

PNode CreateList(  )
{
    int len; //链表长度
    int val; //节点值
    PNode PHead = ( PNode )malloc( sizeof( Node ));
    if ( PHead == NULL ) //判断是否分配成功
    {
        printf( "空间分配失败" );
        exit( -1 );
    }
    
    PNode PTail = PHead; //末尾节点初始为头节点
    PTail->next = NULL; //最后一个节点指针置为空
    printf( "请输入节点个数" );
    scanf( "%d", &len );
    for ( int i = 0; i < len; i++ )
    {
        PNode pNew = ( PNode )malloc( sizeof( Node ) );
        if( pNew == NULL )
        {
            printf( "分配新节点失败" );
            exit( -1 );
        }
        scanf( "%d", &val );
        
        pNew->data = val;
        PTail->next = pNew; //末尾节点指针指向下一个新节点
        pNew->next = NULL; //新节点指针指向为空
        PTail = pNew; //新节点复制给末尾节点
    }
    printf( "链表创建成功" );
    return PHead;
}


void print( PNode h )
{
    PNode p = h->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    PNode List = CreateList();
    print( List );
    
    return 0;
}
