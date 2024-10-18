#ifndef FILEIO_H
#define FILEIO_H

#include "Train.h"
#include "Queue.h"

// Load and save functions
void loadBookingsFromFile(CircularQueue *queue);
void saveTrainSchedulesToFile(Train trains[], int train_count); // Correct signature
int loadTrainSchedulesFromFile(Train trains[], int *train_count); // Ensure this returns int
void saveBookingsToFile(CircularQueue *queue);
void saveTrainDatesToFile(char* date, char* time); // New function for saving train dates

#endif // FILEIO_H
