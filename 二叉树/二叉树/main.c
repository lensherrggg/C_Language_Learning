//
//  main.c
//  二叉树
//
//  Created by Surface Laptop 2 on 2019/8/6.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *Left;
    struct Node *Right;
}Node, *BinaryTree;

/*
BinaryTree CreateTree(){
    BinaryTree Root = (BinaryTree)malloc(sizeof(Node));
    if(Root == NULL){
        printf("Out of space");
        exit(-1);
    }
    Root->Left = NULL;
    Root->Right = NULL;
    
    printf("Succeed to create an empty tree\n");
    return Root;
}
*/

int isEmpty(BinaryTree t){
    return t == NULL;
}

BinaryTree Find(int data, BinaryTree t){
    if(t == NULL){
        return NULL;
    }
    if(data < t->data){
        return Find(data, t->Left);
    }
    if(data > t->data){
        return Find(data, t->Right);
    }
    else{
        return t;
    }
}

BinaryTree FindMin(BinaryTree t){
    if(t == NULL){
        return NULL;
    }
    else if(t->Left == NULL){
        return t;
    }
    else{
        return FindMin(t->Left);
    }
}

BinaryTree FindMax(BinaryTree t){
    if(t == NULL){
        return NULL;
    }
    else if(t->Right == NULL){
        return t;
    }
    else{
        return FindMin(t->Right);
    }
}

BinaryTree Insert(BinaryTree t, int data){
    if(isEmpty(t)){
        t = (BinaryTree)malloc(sizeof(Node));
        if(t == NULL){
            printf("Out of space");
        }
        else{
            t->data = data;
            t->Left = NULL;
            t->Right = NULL;
        }
    }
    else if(data < t->data)
        t->Left = Insert(t->Left, data);
    else if(data > t->data)
        t->Right = Insert(t->Right, data);
    
    return t;
}

BinaryTree Delete(BinaryTree t, int data){
    BinaryTree TmpCell;
    
    if(isEmpty(t)){
        t = (BinaryTree)malloc(sizeof(Node));
        if(t == NULL){
            printf("Out of space");
        }
    }
    else if(data < t->data){
        t->Left = Delete(t->Left, data);
    }
    else if(data > t->data){
        t->Right = Delete(t->Right, data);
    }
    else if(t->Left && t->Right){
        TmpCell = FindMin(t->Right);
        t->data = TmpCell->data;
        t->Right = Delete(t->Right, t->data);
    }
    else{
        TmpCell = t;
        if(t->Left == NULL){
            t = t->Right;
        }
        else if(t->Right == NULL){
            t = t->Left;
        }
    }
    
    return t;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTree T = Insert(T, 2);
    printf("%4d\n", T->data);
    T = Insert(T, 1);
    T = Insert(T, 3);
    //printf("%4d%4d\n", (T->Left)->data, (T->Right)->data);
    //BinaryTree T_Left = T->Left;
    //BinaryTree T_Right = T->Right;
    printf("%4d%4d\n", T->Left->data, T->Right->data);
    printf("%d\n", FindMin(T)->data);
    printf("%d\n",FindMax(T)->data);
    //T = Delete(T, 3);
    //printf("%4d\n", T->Left->data);
    
    return 0;
}
