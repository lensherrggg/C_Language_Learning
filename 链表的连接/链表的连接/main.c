//
//  main.c
//  链表的连接
//
//  Created by Surface Laptop 2 on 2019/8/5.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
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
        PTail->next = pNew;
        pNew->next = NULL;
        PTail = pNew;
    }
    printf( "Succeed to create the linklist. \n" );
    return PHead;
}

void printlist(PNode h){
    PNode p = h->next;
    while( p != NULL )
    {
        printf( "%4d", p->data );
        p = p->next;
    }
    printf( "\n" );
}

PNode ConnectList(PNode h1, PNode h2 ){
    PNode PHead = h1;
    PNode p = ( PNode )malloc( sizeof( Node ) );
    p = h1->next;
    while( p->next != NULL )
    {
        p = p->next;
    }
    
    p->next = h2->next;
    return PHead;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    PNode List1 = CreateList();
    PNode List2 = CreateList();
    printf( "The first linklist: \n" );
    printlist( List1 );
    printf( "The second linklist: \n" );
    printlist( List2 );
    printf( "The connected linklist: \n" );
    printlist( ConnectList(List1, List2));
    //printlist(List);
    
    return 0;
}

