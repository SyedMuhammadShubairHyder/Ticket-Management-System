#include <iostream>
#include <ctime>

#include "Sorting&Searching.h"
using namespace std;

void ticket::DisplayInfo() {
    cout << "Ticket ID: " << Ticketid << endl;
    cout << "Customer Name: " << CustomerName << endl;
    string priority = (Priority == 1) ? "High" : (Priority == 2) ? "Medium" : (Priority == 3) ? "Low" : "Invalid";
    cout << "Priority: " << priority << endl;
    cout << "Description: " << Description << endl;
    cout << "Creation Time: " << ctime(&CreationTime);
    cout << "Status: " << Status << endl;
}


bool binarySearchForid(ticket arr[], int count, int id) {
    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].Ticketid == id) {
            cout<<"Ticket Found "<<endl;
            arr[mid].DisplayInfo();
            return true;
        }
        if (arr[mid].Ticketid < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Ticket Not Found" << endl;
    return false;
}

bool binarySearchForName(ticket arr[], int count, string name) {
    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].CustomerName == name) {
            cout<<"Ticket Found "<<endl;
            arr[mid].DisplayInfo();
            return true;
        }
        if (arr[mid].CustomerName < name) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Ticket Not Found" << endl;
    return false;
}

bool interplationSearchForid(ticket arr[], int count, int id) {
    int left = 0;
    int right = count - 1;
    while (left <= right && id >= arr[left].Ticketid && id <= arr[right].Ticketid) {
        int pos = left + (((double)(right - left) / (arr[right].Ticketid - arr[left].Ticketid)) * (id - arr[left].Ticketid));
        if (arr[pos].Ticketid == id) {
            cout<<"Ticket Found "<<endl;
            arr[pos].DisplayInfo();
            return true;
        }
        if (arr[pos].Ticketid < id) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }

    }
    cout<< "Ticket Not Found" << endl;
    return false;
}

bool interplationSearchForName(ticket arr[], int count, string name) {
    int left = 0;
    int right = count - 1;

    // Ensure the array is sorted by CustomerName before using interpolation search
    while (left <= right && name >= arr[left].CustomerName && name <= arr[right].CustomerName) {
        int denominator = arr[right].CustomerName.compare(arr[left].CustomerName);
        if (denominator == 0) {
            // If both CustomerNames are the same, we can't use interpolation; use linear search
            for (int i = left; i <= right; ++i) {
                if (arr[i].CustomerName == name) {
                    cout<<"Ticket Found "<<endl;
                    arr[i].DisplayInfo();
                    return true;
                }
            }
            break; // Exit if no match found in linear search
        }

        // Calculate the position using the interpolation formula
        int pos = left + ((right - left) / denominator * (name.compare(arr[left].CustomerName)));

        if (pos < left || pos > right) {
            break; // If pos is out of bounds, exit the loop
        }

        // Check for a match
        if (arr[pos].CustomerName == name) {
            cout<<"Ticket Found "<<endl;
            arr[pos].DisplayInfo();
            return true;
        }

        // Update the search bounds
        if (arr[pos].CustomerName < name) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    cout << name << "Ticket Not Found" << endl;
    return false; // Name not found
}

void bubbleSortForPriorty(ticket arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j].Priority > arr[j + 1].Priority) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
       
void selectionSortForPriorty(ticket arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (arr[j].Priority < arr[minIndex].Priority) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertionSortForPriorty(ticket arr[], int count) {
    for (int i = 1; i < count; i++) {
        ticket key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].Priority > key.Priority) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSortForCustumerName(ticket arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j].CustomerName > arr[j + 1].CustomerName) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
       
void selectionSortForCustumerName(ticket arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (arr[j].CustomerName < arr[minIndex].CustomerName) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertionSortForCustumerName(ticket arr[], int count) {
    for (int i = 1; i < count; i++) {
        ticket key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].CustomerName > key.CustomerName) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSortForCreationTime(ticket arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j].CreationTime > arr[j + 1].CreationTime) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
       
void selectionSortForCreationTime(ticket arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (arr[j].CreationTime < arr[minIndex].CreationTime) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertionSortForCreationTime(ticket arr[], int count) {
    for (int i = 1; i < count; i++) {
        ticket key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].CreationTime > key.CreationTime) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void mergeForPriorty(ticket arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    ticket* L = new ticket[n1];
    ticket* R = new ticket[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].Priority <= R[j].Priority) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortForPriorty(ticket arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortForPriorty(arr, left, mid);
        mergeSortForPriorty(arr, mid + 1, right);
        mergeForPriorty(arr, left, mid, right);
    }
}



int partitionForPriorty(ticket array[], int low, int high) {
    ticket pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j].Priority <= pivot.Priority) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSortForPriorty(ticket arr[], int low, int high) {
    if (low < high) {
        int pi = partitionForPriorty(arr, low, high);
        quickSortForPriorty(arr, low, pi - 1);
        quickSortForPriorty(arr, pi + 1, high);
    }
}

void mergeForCustumerName(ticket arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    ticket* L = new ticket[n1];
    ticket* R = new ticket[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].CustomerName <= R[j].CustomerName) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortForCustumerName(ticket arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortForCustumerName(arr, left, mid);
        mergeSortForCustumerName(arr, mid + 1, right);
        mergeForCustumerName(arr, left, mid, right);
    }
}



int partitionForCustumerName(ticket array[], int low, int high) {
    ticket pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j].CustomerName <= pivot.CustomerName) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSortForCustumerName(ticket arr[], int low, int high) {
    if (low < high) {
        int pi = partitionForCustumerName(arr, low, high);
        quickSortForCustumerName(arr, low, pi - 1);
        quickSortForCustumerName(arr, pi + 1, high);
    }
}




int partitionForCreationTime(ticket array[], int low, int high) {
    ticket pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j].CreationTime <= pivot.CreationTime) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSortForCreationTime(ticket arr[], int low, int high) {
    if (low < high) {
        int pi = partitionForCreationTime(arr, low, high);
        quickSortForCreationTime(arr, low, pi - 1);
        quickSortForCreationTime(arr, pi + 1, high);
    }
}


void mergeForCreationTime(ticket arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    ticket* L = new ticket[n1];
    ticket* R = new ticket[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].CreationTime <= R[j].CreationTime) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortForCreationTime(ticket arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortForCreationTime(arr, left, mid);
        mergeSortForCreationTime(arr, mid + 1, right);
        mergeForCreationTime(arr, left, mid, right);
    }
}

