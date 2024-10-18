#ifndef QUEUE_H
#define QUEUE_H

#include "Passenger.h"

#define MAX_QUEUE_SIZE 100

// Forward declaration
struct CircularQueue;
typedef struct CircularQueue {
    Passenger passengers[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} CircularQueue;

// Function prototypes
void enqueue(CircularQueue *queue, Passenger passenger);
Passenger dequeue(CircularQueue *queue);
int isEmpty(CircularQueue *queue);
int isFull(CircularQueue *queue);
void initializeQueue(CircularQueue *queue);
void displayQueue(CircularQueue *queue);

#endif // QUEUE_H
