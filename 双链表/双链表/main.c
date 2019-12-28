//
//  main.c
//  双链表
//
//  Created by Surface Laptop 2 on 2019/8/6.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct Node *next, *prev;
}Node, *PNode;

PNode CreateList()
{
    int len;
    int val;
    PNode PHead = (PNode)malloc(sizeof(Node));
    if(PHead == NULL)
    {
        printf("Failt to create header node. ");
        exit(-1);
    }
    PHead->prev = NULL;
    PNode PTail = PHead;
    PTail->next = NULL;
    
    printf("Please input the length of the list: ");
    scanf("%d", &len);
    
    for(int i = 0; i < len; i++)
    {
        PNode pNew = (PNode)malloc(sizeof(Node));
        if(pNew == NULL){
            printf("Fail to create new node. \n");
            exit(-1);
        }
        
        printf("Please input the data: ");
        scanf("%d", &val);
        
        pNew->data = val;
        PTail->next = pNew;
        pNew->next = NULL;
        pNew->prev = PTail;
        PTail = pNew;
    }
    
    printf("Succeed to create the list. \n");
    return PHead;
}

void printlist(PNode h){
    PNode p = h->next;
    while( p != NULL)
    {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

void reverserprint(PNode h){
    PNode p = h->next;
    while(p->next != NULL)
        p = p->next;
    while(p != h){
        printf("%4d", p->data);
        p = p->prev;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    PNode List = CreateList();
    printlist(List);
    reverserprint(List);
    return 0;
}
