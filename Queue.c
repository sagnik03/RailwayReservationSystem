#include <stdio.h>
#include "Queue.h"

// Initialize the circular queue
void initializeQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// Check if the queue is full
int isFull(CircularQueue *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

// Check if the queue is empty
int isEmpty(CircularQueue *queue) {
    return queue->front == -1;
}

// Enqueue a passenger
void enqueue(CircularQueue *queue, Passenger passenger) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->passengers[queue->rear] = passenger;
    queue->size++;
}

// Dequeue a passenger
Passenger dequeue(CircularQueue *queue) {
    Passenger passenger = {0}; // Initialize to default values
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return passenger; // Return an empty Passenger
    }
    passenger = queue->passengers[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1; // Queue is now empty
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    queue->size--;
    return passenger;
}

// Display current bookings in the queue
void displayQueue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("No bookings available.\n");
        return;
    }
    printf("Current Bookings:\n");
    int i = queue->front;
    while (1) {
        printf("Name: %s, Age: %d, Ticket No: %d\n", queue->passengers[i].name, queue->passengers[i].age, queue->passengers[i].ticket_no);
        if (i == queue->rear) break;
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
}
