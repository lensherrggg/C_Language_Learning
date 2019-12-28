//
//  main.c
//  后缀表达式计算
//
//  Created by Surface Laptop 2 on 2019/8/18.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Node *Stack;

int isEmpty(Stack s){
    return s->next == NULL;
}

void Push(int data, Stack S){
    Stack TmpCell;
    
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("Out of space");
    else{
        TmpCell->data = data;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

int Top(Stack S){
    if(!isEmpty(S))
        return S->next->data;
    else{
        printf("Empty stack");
        return 0;
    }
}

void Pop(Stack S){
    Stack FirstCell;
    
    if(isEmpty(S))
        printf("Empty Stack");
    else{
        FirstCell = S->next;
        S->next = S->next->next;
        free(FirstCell);
    }
}

void MakeEmpty(Stack S){
    if(S == NULL)
        printf("Must use CreateStack First");
    else
        while(!isEmpty(S))
            Pop(S);
}

Stack CreateStack(){
    Stack S;
    
    S = malloc(sizeof(struct Node));
    if(S == NULL)
        printf("Out of space");
    S->next = NULL;
    MakeEmpty(S);
    return S;
}

int isOperator(char op){
    switch(op){
        case '+':
        case '-':
        case '*':
        case '/': return 1;
        default: return 0;
    }
}

int getValue(char op, int oprand1, int oprand2){
    switch(op){
        case '*': return (oprand1 * oprand2);
        case '/': return (oprand1 / oprand2);
        case '+': return (oprand1 + oprand2);
        case '-': return (oprand1 - oprand2);
        default: return 0;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char exp[100];
    int oprand1 = 0;
    int oprand2 = 0;
    int result = 0;
    int pos = 0;
    Stack S = CreateStack();
    printf("Input: \n");
    gets(exp);
    printf("Result: \n");
    while(exp[pos] != '\0' && exp[pos] != '\n'){
        if(isOperator(exp[pos])){
            oprand1 = Top(S);
            Pop(S);
            oprand2 = Top(S);
            Pop(S);
            Push(getValue(exp[pos], oprand1, oprand2), S);
        }
        else
            Push(exp[pos] - 48, S);
        pos++;
    }
    result = Top(S);
    printf("%4d\n", result);
    
    return 0;
}
