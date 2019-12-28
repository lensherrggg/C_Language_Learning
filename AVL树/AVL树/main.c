//
//  main.c
//  AVL树
//
//  Created by Surface Laptop 2 on 2019/8/8.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int Max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

struct AvlNode;
typedef struct AvlNode *AvlTree;
//typedef struct AvlNode *Position;

struct AvlNode{
    int data;
    AvlTree Left;
    AvlTree Right;
    int Height;
}AvlNode;

AvlTree Find(int data, AvlTree T){
    if(T == NULL){
        return NULL;
    }
    else if(data < T->data){
        return Find(data, T->Left);
    }
    else if(data > T->data){
        return Find(data, T->Right);
    }
    else{
        return T;
    }
}

AvlTree FindMax(AvlTree T){
    if(T == NULL){
        return NULL;
    }
    else if(T->Right == NULL){
        return T;
    }
    else{
        return FindMax(T->Right);
    }
}

AvlTree FindMin(AvlTree T){
    if(T == NULL){
        return NULL;
    }
    else if(T->Left == NULL){
        return T;
    }
    else{
        return FindMin(T->Left);
    }
}

static int Height(AvlTree T){
    if(T == NULL){
        return -1;
    }
    else{
        return T->Height;
    }
}

static AvlTree SingleRotateWithLeft(AvlTree K2){
    AvlTree K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;
    
    return K1;
}
static AvlTree SingleRotateWithRight(AvlTree K2){
    AvlTree K1;
    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;
    
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    
    return K1;
}

static AvlTree DoubleRotateWithLeft(AvlTree K3){
    K3->Left = SingleRotateWithRight(K3->Left);
    
    return SingleRotateWithLeft(K3);
}
static AvlTree DoubleRotateWithRight(AvlTree K3){
    K3->Right = SingleRotateWithLeft(K3->Right);
    
    return SingleRotateWithRight(K3);
}

AvlTree Insert(int data, AvlTree T){
    if(T == NULL){
        T = (AvlTree)malloc(sizeof(AvlNode));
        if(T == NULL){
            printf("Out of space");
        }
        else{
            T->data = data;
            T->Left = NULL;
            T->Right = NULL;
            T->Height = 0;
        }
    }
    else if(data < T->data){
        T->Left = Insert(data, T->Left);
        if(Height(T->Left) - Height(T->Right) == 2){
            if(data < T->Left->data){
                T = SingleRotateWithLeft(T);
            }
            else{
                T = DoubleRotateWithLeft(T);
            }
        }
    }
    else if(data > T->data){
        T->Right = Insert(data, T->Right);
        if(Height(T->Right) - Height(T->Left) == 2){
            if(data > T->Right->data){
                T = SingleRotateWithRight(T);
            }
            else{
                T = DoubleRotateWithRight(T);
            }
        }
    }
    
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
