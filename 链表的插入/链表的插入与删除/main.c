//
//  main.c
//  链表的插入与删除
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

void Insertion(int data, int position, PNode h ) //将要插入的值插入到第position位
{
    PNode p = h->next;
    for( int i = 1; i < position - 1; i++ )
        p = p->next;
    PNode pi = ( PNode )malloc( sizeof( Node ) );
    pi->data = data;
    pi->next = p->next;
    p->next = pi;
}

void Deletion(int position, PNode h)
{
    PNode p = h->next;
    for(int i = 1; i < position - 1; i++)
        p = p->next;
    PNode p1;
    p1 = p->next;
    p->next = p1->next;
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


int main(int argc, const char * argv[]) {
    // insert code here...
    PNode List = CreateList();
    printlist(List);
    
    //Insertion(3, 3, List );
    Deletion(3, List);
    printlist( List );
    
    return 0;
}
