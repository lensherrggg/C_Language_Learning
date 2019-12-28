//
//  main.c
//  链表的查找
//
//  Created by Surface Laptop 2 on 2019/8/5.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    int position;
    struct Node *next;
}Node, *PNode;

PNode CreateList()
{
    int len, value;
    PNode PHead = ( PNode )malloc( sizeof( Node ) );
    if( PHead == NULL )
    {
        printf( "Fail to create the head point. " );
        exit( -1 );
    }
    
    PNode PTail = PHead;
    PTail->next = NULL;
    
    printf( "Please input the length of the linklist: " );
    scanf( "%d", &len );
    
    for( int i = 0; i < len; i++ )
    {
        PNode pNew = ( PNode )malloc( sizeof( Node ) );
        if( pNew == NULL )
        {
            printf( "Fail to create the new node. " );
            exit( -1 );
        }
        
        printf( "Please input the value of next node: " );
        scanf( "%d", &value );
        pNew->data = value;
        pNew->position = i + 1;
        PTail->next = pNew;
        pNew->next = NULL;
        PTail = pNew;
    }
    printf( "Succeed to create the linklist. \n" );
    return PHead;
}

PNode GetNode( PNode h, int i ){
    int j = 1;
    PNode p = h->next;
    while( p != NULL && j < i ){
        p = p->next;
        j++;
    }
    if( i == j )
        return p;
    else
        return NULL;
}

PNode GetNodeNum( PNode h, int value ){
    PNode p = h->next;
    while( p != NULL && p->data != value ){
        p = p->next;
    }
    return p;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    PNode List = CreateList();
    
    printf( "%d\n", GetNode(List, 2 )->data );;
    printf( "%d\n", GetNodeNum(List, 4 )->position );
    
    return 0;
}

