//
// Created by hsume on 28/06/2023.
//

#ifndef MATHCOMPILER_QUEUE_H
#define MATHCOMPILER_QUEUE_H

typedef struct
{
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

void initializeQueue(Queue* queue);
int isEmptyQueue(Queue* queue);
void enqueue(Queue* queue, int element);
int dequeue(Queue* queue);
int front(Queue* queue);
int rear(Queue* queue);
void displayQueue(Queue* queue);
void freeQueue(Queue* queue);
void testQueue();

#endif //MATHCOMPILER_QUEUE_H
