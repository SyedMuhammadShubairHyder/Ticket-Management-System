#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <ctime>
struct ticket
{
    int Ticketid;
    std::string CustomerName;
    int Priority;
    std::string Description;
    time_t CreationTime;
    std::string Status;
    time_t CloseTime;
    void DisplayInfo();
};



void bubbleSortForPriorty(ticket arr[], int count);
void selectionSortForPriorty(ticket arr[], int count);
void insertionSortForPriorty(ticket arr[], int count);

void bubbleSortForCustumerName(ticket arr[], int count);
void selectionSortForCustumerName(ticket arr[], int count);
void insertionSortForCustumerName(ticket arr[], int count);

void bubbleSortForCreationTime(ticket arr[], int count);
void selectionSortForCreationTime(ticket arr[], int count);
void insertionSortForCreationTime(ticket arr[], int count);

void mergeForPriorty(ticket arr[], int left, int mid, int right);
void mergeSortForPriorty(ticket arr[], int left, int right);
void quickSortForPriorty(ticket arr[], int low, int high);
int partitionForPriorty(ticket array[], int low, int high);

void mergeForCustumerName(ticket arr[], int left, int mid, int right);
void mergeSortForCustumerName(ticket arr[], int left, int right);
void quickSortForCustumerName(ticket arr[], int low, int high);
int partitionForCustumerName(ticket array[], int low, int high);

void mergeForCreationTime(ticket arr[], int left, int mid, int right);
void mergeSortForCreationTime(ticket arr[], int left, int right);
void quickSortForCreationTime(ticket arr[], int low, int high);
int partitionForCreationTime(ticket array[], int low, int high);


bool binarySearchForid(ticket arr[], int count, int id);
bool binarySearchForName(ticket arr[], int count, std::string name);

bool interplationSearchForid(ticket arr[], int count, int id);
bool interplationSearchForName(ticket arr[], int count, std::string name);


#endif // SORTING_H