#ifndef PASSENGER_H
#define PASSENGER_H

#include "Train.h"

// Forward declaration of CircularQueue
struct CircularQueue;
typedef struct CircularQueue CircularQueue;

typedef struct {
    int id;
    char name[50];
    int age;
    int ticket_no;
    char travel_date[11]; // Format: YYYY-MM-DD
} Passenger;

// Function prototypes
void bookTicket(CircularQueue *queue, Train trains[], int train_count);
void cancelTicket(CircularQueue *queue);
void displayBookings(CircularQueue *queue);

#endif // PASSENGER_H
