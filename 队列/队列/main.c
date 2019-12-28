//
//  main.c
//  队列
//
//  Created by Surface Laptop 2 on 2019/8/6.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct Member *next;
    struct Member *prev;
}Member, *Queue;

Queue CreateQueue()
{
    Queue Front = (Queue)malloc(sizeof(Member));
    if(Front == NULL){
        printf("Out of space! \n");
        exit(-1);
    }
    Front->prev = NULL;
    
    Queue Rear = Front;
    Rear->next = NULL;
    
    printf("Success! \n");
    return Front;
}

int isEmpty(Queue q){
    return q->next == NULL;
}

void EnQueue(int value, Queue q){
    Queue lstMem = q;
    while(lstMem->next != NULL)
        lstMem = lstMem->next;
    Queue newMem = (Queue)malloc(sizeof(Member));
    if(newMem == NULL){
        printf("Out of space");
        exit(-1);
    }
    newMem->data = value;
    lstMem->next = newMem;
    newMem->next = NULL;
    newMem->prev = lstMem;
    lstMem = newMem;
}

void DeQueue(Queue q){
    if(isEmpty(q)){
        printf("Empty Queue\n");
    }
    else{
        Queue lstMem = q->next;
        while(lstMem->next != NULL)
            lstMem = lstMem->next;
        Queue lst2Mem = lstMem->prev;
        lst2Mem->next = NULL;
        lstMem = lst2Mem;
        free(lstMem);
    }
}

void printQueue(Queue q){
    Queue Mem = q->next;
    while(Mem != NULL)
    {
        printf("%4d", Mem->data);
        Mem = Mem->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Queue queue = CreateQueue();
    EnQueue(1, queue);
    EnQueue(2, queue);
    EnQueue(3, queue);
    EnQueue(4, queue);
    printQueue(queue);
    EnQueue(5, queue);
    printQueue(queue);
    
    DeQueue(queue);
    printQueue(queue);
    DeQueue(queue);
    printQueue(queue);
    
    return 0;
}
