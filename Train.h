#ifndef TRAIN_H
#define TRAIN_H

#define MAX_TRAINS 100 

typedef struct {
    int train_no;
    char train_name[50];
    char source[50];
    char destination[50];
    int ticket_price; 
} Train;

void addTrain(Train trains[], int *train_count); // Declaration only

#endif // TRAIN_H
