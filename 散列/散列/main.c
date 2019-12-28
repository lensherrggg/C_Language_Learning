//
//  main.c
//  散列
//
//  Created by Surface Laptop 2 on 2019/8/12.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int data;
    struct ListNode *next;
};

typedef struct ListNode *PNode;
typedef PNode List;

struct HashTbl{
    int TableSize;
    PNode *TheLists;
};

typedef struct HashTbl *HashTable;

int isPrime(int a){
    for(int i = 2; i <= a / 2; i++){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}

int NextPrime(int a){
    int i;
    for(i = a; ; i++){
        if(isPrime(i) == 1){
            break;
        }
    }
    return i;
}


HashTable Initialize(int TableSize)
{
    HashTable H;
    int i;
    int MinTableSize = 1;
    
    if(TableSize < MinTableSize)
    {
        printf("Table size too small");
        return NULL;
    }
    
    H = malloc(sizeof(struct HashTbl));
    if(H == NULL)
        printf("Out of space");
    
    H->TableSize = NextPrime(TableSize);
    
    H->TheLists = malloc(sizeof(PNode) * H->TableSize);
    if(H->TheLists == NULL){
        printf("Out of space");
    }
    
    for(i = 0; i < H->TableSize; i++){
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if(H->TheLists[i] == NULL){
            printf("Out of space");
        }
        else{
            H->TheLists[i]->next = NULL;
        }
    }
    return H;
}

/*
PNode Find(ElementType Key, HashTable H){
    PNode P;
    List L;
    
    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->next;
    while(P != NULL && P->data != Key){ //Probably need strcmp!
        P = P->next;
    }
    return P;
}
*/
/*
void Insert(ElementType Key, HashTable H){
    PNode Pos, NewCell;
    List L;
    
    Pos = Find(Key, H);
    if(Pos == NULL){
        NewCell = malloc(sizeof(struct ListNode));
        if(NewCell == NULL){
            printf("Out of space");
        }
        else{
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->next = L->next;
            NewCell->data = Key; //Probably need strcpy!
            L->next = NewCell;
        }
    }
}
*/

int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}
