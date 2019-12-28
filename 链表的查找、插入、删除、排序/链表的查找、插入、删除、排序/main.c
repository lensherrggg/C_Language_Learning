//
//  main.c
//  链表的查找、插入、删除、排序
//
//  Created by Surface Laptop 2 on 2019/8/16.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coef;
    int expn;
    struct Node *next;
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
    return h;
}

int isEmpty(PNode h){
    return h->next == NULL;
}

int isLast(PNode p){
    return p->next == NULL;
}

PNode Find(int expn, PNode h){
    PNode p = h->next;
    while(p != NULL && p->expn != expn){
        p = p->next;
    }
    return p;
}

PNode FindPrev(int expn, PNode h){
    PNode p = h;
    while(p->next != NULL && p->next->expn != expn){
        p = p->next;
    }
    
    return p;
}

PNode FindMax(PNode h){
    PNode p = h->next;
    PNode TmpCell = p;
    while(p != NULL){
        if(p->expn > TmpCell->expn){
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
        printf("%4d%4d\n", p->coef, p->expn);
        p = p->next;
    }
}


void Insert(PNode h, int coef, int expn){
    PNode TmpCell = (Position)malloc(sizeof(struct Node));
    if(TmpCell == NULL){
        printf("Out of space");
        exit(-1);
    }
    
    PNode p = h;
    while(p->next != NULL){
        p = p->next;
    }
    TmpCell->coef = coef;
    TmpCell->expn = expn;
    TmpCell->next = NULL;
    p->next = TmpCell;
}

void Delete(int expn, PNode h){
    PNode lst = FindPrev(expn, h);
    
    if(!isLast(lst)){
        PNode Tmp = lst->next;
        lst->next = Tmp->next;
    }
}

PNode Sort(PNode h){
    //PNode header = h;
    PNode p = h->next;
    PNode TmpCell;
    PNode NewList = MakeEmpty();
    int expn;
    while(h->next != NULL){
        PNode max = FindMax(h);
        expn = max->expn;
        PNode f = Find(expn, NewList);
        if(f == NULL){
            Insert(NewList, max->coef, expn);
        }
        else{
            f->coef = f->coef + max->coef;
        }
        Delete(expn, h);
    }
    
    return NewList;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    PNode L1 = MakeEmpty();
    printf("%d", isEmpty(L1));
    PNode L2 = MakeEmpty();
    Insert(L1, 1, 2);
    Insert(L1, 2, 3);
    Insert(L1, 3, 5);
    Insert(L1, 4, 0);
    Insert(L1, 2, 6);
    printf("L1:\n");
    L1 = Sort(L1);
    printList(L1);
    
    Insert(L2, 1, 2);
    Insert(L2, 2, 7);
    Insert(L2, 3, 4);
    Insert(L2, 4, 3);
    Insert(L2, 5, 0);
    printf("L2:\n");
    L2 = Sort(L2);
    printList(L2);
    //printf("L3: \n");
    //PNode L3 = PolyMult(L1, L2);
    //L3 = Sort(L3);
    //PNode L3 = MakeEmpty();
    //printList(L3);
    
    return 0;
}

