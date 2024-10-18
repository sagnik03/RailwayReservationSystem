#include <stdio.h>
#include <string.h>
#include "Train.h"

void addTrain(Train trains[], int *train_count) {
    if (*train_count >= MAX_TRAINS) {
        printf("Train list is full.\n");
        return;
    }
    
    printf("Enter train number: ");
    scanf("%d", &trains[*train_count].train_no);
    getchar(); // Clear the newline character left by scanf
    
    printf("Enter train name: ");
    fgets(trains[*train_count].train_name, sizeof(trains[*train_count].train_name), stdin);
    trains[*train_count].train_name[strcspn(trains[*train_count].train_name, "\n")] = 0; // Remove the newline character
    
    printf("Enter source: ");
    fgets(trains[*train_count].source, sizeof(trains[*train_count].source), stdin);
    trains[*train_count].source[strcspn(trains[*train_count].source, "\n")] = 0; // Remove the newline character
    
    printf("Enter destination: ");
    fgets(trains[*train_count].destination, sizeof(trains[*train_count].destination), stdin);
    trains[*train_count].destination[strcspn(trains[*train_count].destination, "\n")] = 0; // Remove the newline character
    
    printf("Enter ticket price: ");
    scanf("%d", &trains[*train_count].ticket_price);
    (*train_count)++;

    printf("Train added successfully: %s (%d)\n", trains[*train_count - 1].train_name, trains[*train_count - 1].train_no);
}
