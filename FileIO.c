#include <stdio.h>
#include <stdlib.h>
#include "FileIO.h"

// Load bookings from a file into the queue
void loadBookingsFromFile(CircularQueue *queue) {
    FILE *file = fopen("bookings.txt", "r"); // Open the bookings file for reading
    if (file == NULL) {
        printf("Could not open bookings file for reading.\n");
        return;
    }

    Passenger passenger = {0}; // Initialize to default values
    while (fscanf(file, "%s %d %d", passenger.name, &passenger.age, &passenger.ticket_no) == 3) {
        enqueue(queue, passenger); // Add the passenger to the queue
    }

    fclose(file);
    printf("Bookings loaded successfully.\n");
}

// Save train schedules (train details) to a file
void saveTrainSchedulesToFile(Train trains[], int train_count) {
    FILE *file = fopen("trains.txt", "w"); // Use trains.txt for details
    if (!file) {
        printf("Failed to open file for saving train schedules.\n");
        return;
    }
    for (int i = 0; i < train_count; i++) {
        fprintf(file, "%d %s %s %s %d\n", 
                trains[i].train_no, trains[i].train_name, trains[i].source, trains[i].destination, trains[i].ticket_price);
    }
    fclose(file);
    printf("Train schedules saved successfully to trains.txt.\n");
}

// Save bookings from the queue to a file
void saveBookingsToFile(CircularQueue *queue) {
    FILE *file = fopen("bookings.txt", "w"); // Open the bookings file for writing
    if (file == NULL) {
        printf("Could not open bookings file for writing.\n");
        return;
    }

    int size = queue->size;
    int i = queue->front;

    while (size--) {
        fprintf(file, "%s %d %d\n", queue->passengers[i].name, queue->passengers[i].age, queue->passengers[i].ticket_no);
        i = (i + 1) % MAX_QUEUE_SIZE; // Move to the next passenger
    }

    fclose(file);
    printf("Bookings saved successfully to bookings.txt.\n");
}

// Save train schedules (dates and timings) to a file
void saveTrainDatesToFile(char* date, char* time) {
    FILE *file = fopen("train_schedules.txt", "a"); // Append to the file
    if (!file) {
        printf("Failed to open file for saving train dates.\n");
        return;
    }
    fprintf(file, "%s %s\n", date, time);
    fclose(file);
    printf("Train dates and timings saved successfully to train_schedules.txt.\n");
}

// Load train schedules (dates and timings) from a file
int loadTrainSchedulesFromFile(Train trains[], int *train_count) {
    FILE *file = fopen("train_schedules.txt", "r");
    if (file == NULL) {
        printf("Could not open train schedules file for reading.\n");
        return 0; // Indicate failure
    }

    char date[11], time[6]; // Assuming date format is YYYY-MM-DD and time is HH:MM
    while (fscanf(file, "%s %s", date, time) == 2) {
        // You might want to associate these with trains in your structure.
        // For example, you can store them in an array of structs if you have a schedule structure.
        printf("Loaded schedule - Date: %s, Time: %s\n", date, time);
        // Increment train count if you are storing them
        (*train_count)++; // This is just an example; adjust based on your structure
    }
    fclose(file);
    return *train_count; // Return the number of loaded schedules
}
