//
// Created by hsume on 27/06/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

typedef struct
{
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

void initializeQueue(Queue* queue)
{
    const int initialCapacity = 5; // Capacidade inicial da fila
    queue->data = malloc(initialCapacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = initialCapacity;
}

int isEmptyQueue(Queue* queue)
{
    return queue->size == 0;
}

void enqueue(Queue* queue, int element)
{
    if (queue->size == queue->capacity)
    {
        // A capacidade da fila está esgotada, realocar com uma capacidade maior
        queue->capacity *= 2;
        queue->data = realloc(queue->data, queue->capacity * sizeof(int));
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = element;
    queue->size++;
}

int dequeue(Queue* queue)
{
    if (isEmptyQueue(queue))
    {
        printf("Erro: a fila está vazia.\n");
        return -1;
    }

    int element = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return element;
}

int front(Queue* queue)
{
    if (isEmptyQueue(queue))
    {
        printf("Erro: a fila está vazia.\n");
        return -1;
    }

    return queue->data[queue->front];
}

int rear(Queue* queue)
{
    if (isEmptyQueue(queue))
    {
        printf("Erro: a fila está vazia.\n");
        return -1;
    }

    return queue->data[queue->rear];
}

void displayQueue(Queue* queue)
{
    if (isEmptyQueue(queue))
    {
        printf("A fila está vazia.\n");
        return;
    }

    printf("Elementos da fila: ");
    int i;

    for (i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity)
    {
        printf("%d ", queue->data[i]);
    }
    printf("%d\n", queue->data[i]);
}

void freeQueue(Queue* queue)
{
    free(queue->data);
}

void testQueue()
{
    Queue queue;
    initializeQueue(&queue);

    // Exemplo de uso
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    displayQueue(&queue); // Saída: Elementos da fila: 10 20 30

    dequeue(&queue);

    displayQueue(&queue); // Saída: Elementos da fila: 20 30

    freeQueue(&queue);
}