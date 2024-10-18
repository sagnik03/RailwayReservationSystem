#include <stdio.h>
#include <string.h>
#include "Passenger.h"
#include "Queue.h"
#include "Train.h"  // Include Train.h to use the Train type

void bookTicket(CircularQueue *queue, Train trains[], int train_count) {
    Passenger passenger;

    // Get passenger name
    printf("Enter passenger name: ");
    getchar(); // Clear newline from buffer
    fgets(passenger.name, sizeof(passenger.name), stdin);
    passenger.name[strcspn(passenger.name, "\n")] = 0; // Remove the newline character

    // Get passenger age
    printf("Enter passenger age: ");
    scanf("%d", &passenger.age);
    passenger.ticket_no = queue->rear + 1; // Simple ticket numbering

    // Ask for source and destination
    char source[50], destination[50];
    printf("Enter source: ");
    getchar(); // Clear newline from buffer
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = 0; // Remove the newline character

    printf("Enter destination: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = 0; // Remove the newline character

    // Ask for travel date
    char travel_date[11]; // Format: YYYY-MM-DD
    printf("Enter travel date (YYYY-MM-DD): ");
    scanf("%s", travel_date);
    strcpy(passenger.travel_date, travel_date); // Store the travel date in the passenger struct

    // Display available trains
    int available = 0; // Flag to check if any train is available
    printf("Available trains:\n");
    for (int i = 0; i < train_count; i++) {
        if (strcmp(trains[i].source, source) == 0 && strcmp(trains[i].destination, destination) == 0) {
            printf("Train No: %d, Train Name: %s\n", trains[i].train_no, trains[i].train_name);
            available = 1; // Set flag if at least one train is found
        }
    }

    if (!available) {
        printf("No trains available from %s to %s.\n", source, destination);
        return; // Exit the function if no trains are available
    }

    // Assume a fixed cost for simplicity
    float ticket_cost = 100.0; // Placeholder for ticket cost
    printf("Ticket cost: ₹%.2f\n", ticket_cost);
    
    // Enqueue the passenger
    enqueue(queue, passenger);
    printf("Ticket booked for %s on %s\n", passenger.name, passenger.travel_date);
}

void cancelTicket(CircularQueue *queue) {
    Passenger passenger = dequeue(queue);
    if (passenger.ticket_no != 0) {
        printf("Ticket canceled for %s\n", passenger.name);
    } else {
        printf("No tickets to cancel.\n");
    }
}

void displayBookings(CircularQueue *queue) {
    displayQueue(queue); // Call to display the current queue
}
