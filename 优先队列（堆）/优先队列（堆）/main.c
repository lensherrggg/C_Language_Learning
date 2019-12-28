//
//  main.c
//  优先队列（堆）
//
//  Created by Surface Laptop 2 on 2019/8/12.
//  Copyright © 2019 Surface Laptop 2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct HeapStruct{
    int Capacity;
    int Size;
    int *Elements;
};

typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    int MinData = 0;
    int MinPQSize = 1;
    
    if(MaxElements < MinPQSize)
    {
        printf("Priority queue size is too small");
    }
    H = malloc(sizeof(struct HeapStruct));
    if(H == NULL)
    {
        printf("Out of space");
    }
    
    H->Elements = malloc((MaxElements + 1) * sizeof(int));
    if(H->Elements == NULL)
    {
        printf("Out of space");
    }
    
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;
    
    return H;
}

int isFull(PriorityQueue H)
{
    if(H->Size >= H->Capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(PriorityQueue H)
{
    if(H->Size == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void Insert(int X, PriorityQueue H)
{
    int i;
    
    if(isFull(H))
    {
        printf("Priority queue is full");
        return;
    }
    
    for(i = ++H->Size; H->Elements[i / 2] > X; i = i / 2)
    {
        H->Elements[i] = H->Elements[i / 2];
    }
    H->Elements[i] = X;
}

int DeleteMin(PriorityQueue H)
{
    int i, Child;
    int MinElement, LastElement;
    if(isEmpty(H))
    {
        printf("Priority queue is empty");
        return H->Elements[0];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];
    
    for(i = 1; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;
        if(Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
        {
            Child++;
        }
        
        if(LastElement > H->Elements[Child]){
            H->Elements[i] = H->Elements[Child];
        }
        else{
            break;
        }
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
