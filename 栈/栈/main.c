//
//  main.c
//  栈
//
//  Created by Surface Laptop 2 on 2019/8/6.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct Cell *next;
}Cell, *Stack;

Stack CreateStack()
{
    Stack Top = (Stack)malloc(sizeof(Cell));
    if(Top == NULL)
    {
        printf("Out of space! ");
        exit(-1);
    }
    Stack Bottom = Top;
    Bottom->next = NULL;
    
    printf("Success\n");
    return Top;
}

int isEmpty(Stack t){
    return t->next == NULL;
}

void Push(int i, Stack t){
    Stack TmpCell = (Stack)malloc(sizeof(Cell));
    if(TmpCell == NULL)
    {
        printf("Out of space! ");
        exit(-1);
    }
    TmpCell->data = i;
    TmpCell->next = t->next;
    t->next = TmpCell;
}

void Pop(Stack t){
    if(isEmpty(t)){
        printf("Empty stack\n");
    }
    else{
    Stack fstCell = t->next;
    t->next = fstCell->next;
    free(fstCell);
    }
}

void printStack(Stack t){
    Stack c = t->next;
    while( c != NULL){
        printf("%4d", c->data);
        c = c->next;
    }
    printf("\n");
}

void printTop(Stack t){
    if(isEmpty(t)){
        printf("Empty stack\n");
    }
    else{
        Stack fstCell = t->next;
        printf("%d\n", fstCell->data);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Stack stack = CreateStack();
    Push(1, stack);
    //printStack(stack);
    printTop(stack);
    Push(2, stack);
    //printStack(stack);
    printTop(stack);
    Push(3, stack);
    //printStack(stack);
    printTop(stack);
    Push(4, stack);
    //printStack(stack);
    printTop(stack);
    Pop(stack);
    //printStack(stack);
    printTop(stack);
    /*
    Pop(stack);
    printStack(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    */
    return 0;
}
