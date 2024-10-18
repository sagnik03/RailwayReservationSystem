#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Train.h"
#include "Passenger.h"
#include "Queue.h"
#include "FileIO.h"

#define ADMIN_PASSWORD "admin_password" // Define the admin password

// Function to validate admin login
int isAdmin() {
    char password[20];
    printf("Enter admin password: ");
    scanf("%19s", password); // Limit input size to avoid overflow
    return strcmp(password, ADMIN_PASSWORD) == 0; // Compare entered password with predefined password
}

// Admin menu for managing train schedules
void adminMenu(Train trains[], int *train_count) {
    while (1) {
        printf("\nAdmin Menu:\n");
        printf("1. Add Train\n");
        printf("2. View All Trains\n");
        printf("3. Save Train Schedules\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addTrain(trains, train_count); // Admin can add trains
                break;
            case 2:
                // View all trains
                printf("Current Trains:\n");
                for (int i = 0; i < *train_count; i++) {
                    printf("Train No: %d, Name: %s, Source: %s, Destination: %s, Price: ₹%d\n", 
                           trains[i].train_no, trains[i].train_name, trains[i].source, trains[i].destination, trains[i].ticket_price);
                }
                break;
            case 3: {
                saveTrainSchedulesToFile(trains, *train_count); // Save train schedules
                printf("Train schedules saved successfully.\n");
                break;
            }
            case 4:
                return; // Logout
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// User menu for managing bookings
void userMenu(CircularQueue *queue, Train trains[], int train_count) {
    while (1) {
        printf("\nUser Menu:\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Bookings\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                bookTicket(queue, trains, train_count); // User books a ticket
                break;
            case 2:
                cancelTicket(queue); // User cancels a ticket
                break;
            case 3:
                displayBookings(queue); // User displays bookings
                break;
            case 4:
                return; // Logout
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Main function
int main() {
    CircularQueue queue; // Declare a queue for managing bookings
    Train trains[MAX_TRAINS]; // Array to hold train data
    int train_count = 0; // Counter for the number of trains
    
    initializeQueue(&queue); // Initialize the queue
    loadTrainSchedulesFromFile(trains, &train_count); // Load trains from file

    while (1) {
        printf("\nRailway Reservation System\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                if (isAdmin()) {
                    adminMenu(trains, &train_count); // If admin, enter admin menu
                } else {
                    printf("Incorrect password. Access denied.\n");
                }
                break;
            }
            case 2:
                userMenu(&queue, trains, train_count); // Enter user menu
                break;
            case 3:
                saveBookingsToFile(&queue); // Save bookings before exiting
                saveTrainSchedulesToFile(trains, train_count); // Save trains before exit
                return 0; // Exit program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
