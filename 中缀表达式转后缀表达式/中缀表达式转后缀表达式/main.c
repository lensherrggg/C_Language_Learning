//
//  main.c
//  中缀表达式转后缀表达式
//
//  Created by Surface Laptop 2 on 2019/8/18.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
}Node;

typedef struct Node *Stack;

int isEmpty(Stack s){
    return s->next == NULL;
}

void Push(char data, Stack S){
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

char Top(Stack S){
    if(!isEmpty(S))
        return S->next->data;
    else{
        printf("Empty stack");
        return -1;
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
        case '*':
        case '(':
        case ')': return 1;
        default: return 0;
    }
}

int weight(char op){
    switch(op){
        case '+': return 1;
        case '*': return 2;
        case '(': return 3;
        case ')': return 3;
        default: return 0;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char inputexp[100];
    char outputexp[100];
    int pos1 = 0;
    int pos2 = 0;
    Stack S = CreateStack();
    printf("Input: \n");
    gets(inputexp);
    printf("Result: \n");
    
    while(inputexp[pos1] != '\0' && inputexp[pos1] != '\n'){
        if(!isOperator(inputexp[pos1])){
            outputexp[pos2] = inputexp[pos1];
            pos1++;
            pos2++;
        }
        else{
            if(inputexp[pos1] == ')'){
                while(Top(S) != '('){
                    outputexp[pos2] = Top(S);
                    pos2++;
                    Pop(S);
                }
                Pop(S);
                pos1++;
            }
            else if(inputexp[pos1] == '('){
                Push(inputexp[pos1], S);
                pos1++;
            }
            else if(!isEmpty(S) && weight(inputexp[pos1]) < Top(S)){
                while(!isEmpty(S) && weight(Top(S)) >= weight(inputexp[pos1])){
                    if(Top(S) == '(')
                        break;
                    outputexp[pos2] = Top(S);
                    pos2++;
                    Pop(S);
                }
                Push(inputexp[pos1], S);
                pos1++;
            }
            else{
                Push(inputexp[pos1], S);
                pos1++;
            }
        }
    }
    while(!isEmpty(S)){
        outputexp[pos2] = Top(S);
        pos2++;
        Pop(S);
    }
    outputexp[pos2] = '\0';
    puts(outputexp);
    
    
    return 0;
}
