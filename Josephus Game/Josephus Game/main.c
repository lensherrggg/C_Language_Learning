//
//  main.c
//  Josephus Game
//
//  Created by Surface Laptop 2 on 2019/8/16.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct Node *PNode;
typedef struct Node *Position;

PNode MakeEmpty(){
    PNode h = (PNode)malloc(sizeof(struct Node));
    if(h == NULL){
        printf("Out of space");
        exit(-1);
    }
    
    h->next = NULL;
    h->prev = NULL;
    return h;
}

int isEmpty(PNode h){
    return h->next == NULL;
}

int isLast(PNode p){
    return p->next == NULL;
}

PNode Find(int val, PNode h){
    PNode p = h->next;
    while(p != NULL && p->data != val){
        p = p->next;
    }
    return p;
}

PNode FindLast(PNode h){
    PNode p = h;
    while(p->next != NULL)
        p = p->next;
    return p;
}

PNode FindPrev(int val, PNode h){
    return Find(val, h)->prev;
}

PNode FindMax(PNode h){
    PNode p = h->next;
    PNode TmpCell = p;
    while(p != NULL){
        if(p->data > TmpCell->data){
            TmpCell = p;
        }
        p = p->next;
    }
    return TmpCell;
}

int ListLength(PNode h){
    int i = 0;
    PNode p = h->next;
    while(p != NULL){
        p = p->next;
        i = i + 1;
    }
    return i;
}

void printList(PNode h){
    PNode p = h->next;
    while(p != NULL){
        printf("%4d\n", p->data);
        p = p->next;
    }
}


void Insert(PNode h, int val){
    PNode TmpCell = (Position)malloc(sizeof(struct Node));
    if(TmpCell == NULL){
        printf("Out of space");
        exit(-1);
    }
    
    PNode p = h;
    while(p->next != NULL){
        p = p->next;
    }
    TmpCell->data = val;
    TmpCell->next = NULL;
    TmpCell->prev = p;
    p->next = TmpCell;
}

void Delete(int val, PNode h){
    PNode Tmp = Find(val, h);
    if(isLast(Tmp)){
        PNode lst = Tmp->prev;
        lst->next = NULL;
    }
    else{
        PNode lst = Tmp->prev;
        PNode nxt = Tmp->next;
        lst->next = nxt;
        nxt->prev = lst;
    }
}


PNode Sort(PNode h){
    PNode NewList = MakeEmpty();
    int data;
    while(h->next != NULL){
        PNode max = FindMax(h);
        data = max->data;
        Insert(NewList, max->data);
        Delete(data, h);
    }
    
    return NewList;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    PNode L1 = MakeEmpty();
    int i, j;
    int M = 1;
    int N = 5;
    for(i = 1; i <= N; i++){
        Insert(L1, i);
    }
    PNode p = L1->next;
    for(i = N; i > 1; i--){
        int m = M % N;
        if(m < N / 2){
            for(j = 0; j < m; j++){
                if(p->next == NULL)
                    p = L1->next;
                else
                    p = p->next;
            }
        }
        else{
            for(j = 0; j < N - m; j++){
                if(p->prev == L1)
                    p = FindLast(L1);
                else
                    p = p->prev;
            }
        }
        int num = p->data;
        if(p->next == NULL)
            p = L1->next;
        else
            p = p->next;
        Delete(num, L1);
        printf("No.%3d out\n", num);
    }
    printList(L1);
    
    return 0;
}

