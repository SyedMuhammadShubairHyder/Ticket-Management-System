
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <cstdlib>
using namespace std::chrono; // For high_resolution_clock
using namespace std;
struct ticket
{
    int Ticketid;
    std::string CustomerName;
    int Priority;
    std::string Description;
    time_t CreationTime;
    std::string Status;
    time_t CloseTime;
    void DisplayInfo(){
    cout << "Ticket ID: " << Ticketid << endl;
    cout << "Customer Name: " << CustomerName << endl;
    string priority = (Priority == 1) ? "High" : (Priority == 2) ? "Medium" : (Priority == 3) ? "Low" : "Invalid";
    cout << "Priority: " << priority << endl;
    cout << "Description: " << Description << endl;
    cout << "Creation Time: " << ctime(&CreationTime);
    cout << "Status: " << Status << endl;
}

	
};

class Ticket {
    int Ticketid;
    std::string CustomerName;
    int Priority;
    std::string Description;
    time_t CreationTime; 
    std::string Status; 
    time_t CloseTime;
    

public:
    Ticket* Next;
	Ticket(int id, string name, int priority, string desc) : Ticketid(id), CustomerName(name), Priority(priority), Description(desc), Status("open"), Next(NULL)
    {
        CreationTime = time(NULL);
    }
    

    // for copy constructor
    Ticket(int id, string name, int priority, string desc, time_t creationtime) : Ticketid(id), CustomerName(name), Priority(priority), Description(desc), Status("open"), CreationTime(creationtime), Next(NULL) {}

    int  getTicketId()
    {
        return Ticketid;
    }
    string getCustomerName()
    
    {
        return CustomerName;
    }
    int  getPriorityint()
    {
        return Priority;
    }

    void closeTicket()
    {
        Status = "closed";
        CloseTime = time(NULL);
    }
    string getPriority()
    {

        if (Priority == 3)
        {
            return "Low";
        }
        else if (Priority == 2)
        {
            return "Medium";
        }
        else if (Priority == 1)
        {
            return "High";
        }
        else
        {
            return "Invalid";
        }
    }
    string getDescription()
    {
        return Description;
    }
    time_t getCreationTime()
    {
        return CreationTime;
    }
    string getCreationTimeString()
    {
        string ct = ctime(&CreationTime);
        return ct;
    }
    string getStatus()
    {
        return Status;
    }

    void setStatus(string st)
    {
        Status = st;
    }
    time_t getCloseTime()
    {
        return CloseTime;
    }
    string getCloseTimeString()
    {
        string ct = ctime(&CloseTime);
        return ct;
    }
   
    void viewTicket()
    {   
        cout<<endl;
        cout << "Ticket ID: " << Ticketid << endl<<"Customer Name: " << CustomerName << endl<< "Priority: " << getPriority() << endl<< "Description: " << Description << endl<< "Creation Time: " << getCreationTimeString()  ;
        if(Status=="closed")
        {
            cout<<"Status: "<<Status<<endl;
            cout<<"Closed Time: "<<getCloseTimeString()<<endl;
        }
        else
        {
            cout<<"Status: "<<Status<<endl;
        }
        cout<<endl;
    }    
};

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


class ServiceRequest {
private:
    Ticket* startData;
    int count;
    Ticket* pendingTickets; // priority queue
    Ticket* closedTickets;  // stack

public:
ServiceRequest() : startData(NULL), pendingTickets(NULL), closedTickets(NULL), count(0) {}

// add a ticket when it is ressolve and it status is closed
void pushinLOG(Ticket *newTicket)
{
    newTicket->Next = closedTickets; // Set the new ticket's next to the current top
    closedTickets = newTicket;       // Update the top to the new ticket
    cout << "Ticket with ID " << newTicket->getTicketId() << " added to Resolution log.\n";
}
// Display the recent logs
void DisplayRecentLogs()
{
    cout << "\t\t\t\tRECENT LOGS\n";
    if (closedTickets == NULL)
    {
        cout << "Currently, no tickets available.\n";
        return;
    }

    Ticket *temp = closedTickets;
    while (temp != NULL)
    {
        temp->viewTicket();
        temp = temp->Next;
    }
}
// helper function to find ticket by id
Ticket *findTicketById(int id)
{
    Ticket *temp = startData;
    while (temp != nullptr)
    {
        if (temp->getTicketId() == id)
        {
            return temp; // Return the ticket if found
        }
        temp = temp->Next;
    }
    return nullptr; // Return null if not found
}
// To Search tickets
bool SearchTicket()
{
    ifstream file("Searchconfigfile.txt");
    if (!file.is_open())
    {
        cout << "Unable to open file" << endl;
    }
    string line;
    getline(file, line);
    file.close();

    int choice;
    cout << "Enter the searching creteria you want to set  " << endl
         << "1. Ticket Id" << endl
         << "2. Custumer Name" << endl;
    cin >> choice;

    if (choice == 1)
    {
        return searchbyTicketId(line);
    }
    else if (choice == 2)
    {
        return searchbyCustumerName(line);
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}
// To Sorts tickets
void SortsTicket()
{
    ifstream file;
    if (count < 10)
        file.open("Elementryconfigfile.txt");
    else
        file.open("Advanceconfigfile.txt");

    if (!file.is_open())
    {
        cout << "Unable to open file" << endl;
    }
    string line;
    getline(file, line);
    file.close();

    int choice;
    cout << "Enter the sorting creteria you want to set  " << endl
         << "1. Prioty" << endl
         << "2. Creation Time" << endl
         << "3. Custumer Name" << endl;
    cin >> choice;

    if (choice == 1)
    {
        // sort by prioty
        sortbyPrioty(line);
    }
    else if (choice == 2)
    {
        // sort by creation time
        sortbyCreationTime(line);
    }
    else if (choice == 3)
    {
        // Sort by customer name
        sortbyCustomerName(line);
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}
// add a ticket in pending tickets having only open tickets
void AddInPendingQueue(Ticket *toAdd)
{
    Ticket *newNode = toAdd;

    if (pendingTickets == NULL || pendingTickets->getPriorityint() > toAdd->getPriorityint())
    {
        newNode->Next = pendingTickets;
        pendingTickets = newNode;
    }
    else
    {
        Ticket *current = pendingTickets;
        while (current->Next != nullptr && current->Next->getPriorityint() <= toAdd->getPriorityint())
        {
            current = current->Next;
        }
        newNode->Next = current->Next;
        current->Next = newNode;
    }
}
// view pending queue
void ViewPendingQueue()
{
    cout << "\t\t\t\tOPEN TICKETS\n";
    if (pendingTickets == NULL)
    {
        cout << "Currently, no tickets available.\n";
        return;
    }

    Ticket *temp = pendingTickets;
    while (temp != NULL)
    {
        temp->viewTicket();
        temp = temp->Next;
    }
}

// add a ticket in data base having both closed and open tickets
void AddinAllTicket(Ticket *toAdd)
{
    if (startData == NULL)
    {
        startData = toAdd;
        cout << "Ticket with ID " << toAdd->getTicketId() << " added successfully.\n";
        Ticket *clonedTicket = new Ticket(*toAdd);
        AddInPendingQueue(clonedTicket);
        count++;
        return;
    }

    Ticket *temp = startData;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = toAdd;

    Ticket *clonedTicket = new Ticket(*toAdd);
    AddInPendingQueue(clonedTicket);
    count++;
    cout << "Ticket with ID " << toAdd->getTicketId() << " added successfully.\n";
}

// Remove a ticket by its ID.
void removefromAllTicket(int id)
{
    if (startData == NULL)
    {
        cout << "Currently, no tickets available.\n";
        return;
    }

    if (startData->getTicketId() == id)
    {
        Ticket *toDelete = startData;
        startData = startData->Next;
        delete toDelete;
        count--;
        cout << "Ticket with ID " << id << " removed successfully.\n";
        return;
    }

    Ticket *curr = startData;
    Ticket *prev = NULL;
    while (curr != NULL && curr->getTicketId() != id)
    {
        prev = curr;
        curr = curr->Next;
    }

    if (curr == NULL)
    {
        cout << "Ticket with ID " << id << " not found.\n";
        return;
    }

    prev->Next = curr->Next;
    delete curr;
    count--;
    cout << "Ticket with ID " << id << " removed successfully.\n";
}
// remove ticket from pending queue
void removefromPendingTicket(int id)
{

    if (pendingTickets == NULL)
    {
        cout << "Currently, no tickets available.\n";
        return;
    }

    // Check if the ticket to be removed is the head
    if (pendingTickets->getTicketId() == id)
    {
        cout << "Ticket ID " << id << " found at the head of the list.\n";
        Ticket *toDelete = pendingTickets;
        pendingTickets = pendingTickets->Next;
        delete toDelete;
        cout << "Ticket with ID " << id << " removed successfully.\n";
        return;
    }
}
// get pending tickets
Ticket *getPendingTickets()
{
    if (pendingTickets == NULL)
    {
        cout << "No pending tickets available.\n";
        return NULL; // Return NULL if there are no tickets
    }

    Ticket *toret = pendingTickets;        // Store the current ticket to return
    pendingTickets = pendingTickets->Next; // Move to the next ticket
    toret->Next = NULL;                    // Optional: Disconnect the returned ticket from the list

    return toret; // Return the current ticket
}

// Display all tickets in the database
void DisplayTickets()
{
    if (startData == NULL)
    {
        cout << "Currently, no tickets available.\n";
        return;
    }
    cout << endl;
    cout << "\t\t\t\tTICKETS DATABASE" << endl;
    Ticket *temp = startData;
    while (temp != NULL)
    {
        temp->viewTicket();
        temp = temp->Next;
    }
}

bool searchbyTicketId(string line)
{
    int id;
    cout << "Enter the ticket ID you want to search: ";
    cin >> id;

    ticket *array = new ticket[count + 1];
    Ticket *temp = startData;
    for (int i = 0; i < count; i++)
    {
        array[i].Ticketid = temp->getTicketId();
        array[i].CustomerName = temp->getCustomerName();
        array[i].Priority = temp->getPriorityint();
        array[i].Description = temp->getDescription();
        array[i].CreationTime = temp->getCreationTime();
        array[i].Status = temp->getStatus();
        temp = temp->Next;
    }

    if (line == "BinarySearch")
    {
        return binarySearchForid(array, count, id);
    }
    else if (line == "InterpolationSearch")
    {
        return interplationSearchForid(array, count, id);
    }

    else
    {
        cout << "Invalid searching method" << endl;
    }
}

bool  searchbyCustumerName(string line)
{
    string name;
    cout << "Enter the customer name you want to search: ";
    cin >> name;

    ticket *array = new ticket[count + 1];
    Ticket *temp = startData;
    for (int i = 0; i < count; i++)
    {
        array[i].Ticketid = temp->getTicketId();
        array[i].CustomerName = temp->getCustomerName();
        array[i].Priority = temp->getPriorityint();
        array[i].Description = temp->getDescription();
        array[i].CreationTime = temp->getCreationTime();
        array[i].Status = temp->getStatus();
        temp = temp->Next;
    }

    if (line == "BinarySearch")
    {
        return binarySearchForName(array, count, name);
    }
    else if (line == "InterpolationSearch")
    {
        return interplationSearchForName(array, count, name);
    }

    else
    {
        cout << "Invalid searching method" << endl;
    }
}

void sortbyPrioty(string line)
{
    ticket *array = new ticket[count + 1];
    Ticket *temp = startData;
    for (int i = 0; i < count; i++)
    {
        array[i].Ticketid = temp->getTicketId();
        array[i].CustomerName = temp->getCustomerName();
        array[i].Priority = temp->getPriorityint();
        array[i].Description = temp->getDescription();
        array[i].CreationTime = temp->getCreationTime();
        array[i].Status = temp->getStatus();
        temp = temp->Next;
    }

    if (line == "BubbleSort")
    {
        bubbleSortForPriorty(array, count);
    }
    else if (line == "SelectionSort")
    {
        selectionSortForPriorty(array, count);
    }
    else if (line == "InsertionSort")
    {
        insertionSortForPriorty(array, count);
    }
    else if (line == "QuickSort")
    {
        quickSortForPriorty(array, 0, count - 1);
    }
    else if (line == "MergeSort")
    {
        mergeSortForPriorty(array, 0, count - 1);
    }

    else
    {
        cout << "Invalid sorting method" << endl;
    }

    startData = new Ticket(array[0].Ticketid, array[0].CustomerName, array[0].Priority, array[0].Description, array[0].CreationTime);
    Ticket *current = startData;
    for (int i = 1; i < count; i++)
    {
        Ticket *newTicket = new Ticket(array[i].Ticketid, array[i].CustomerName, array[i].Priority, array[i].Description, array[i].CreationTime);
        current->Next = newTicket;
        current = newTicket;
    }
}

void  sortbyCreationTime(string line)
{
    ticket *array = new ticket[count + 1];
    Ticket *temp = startData;
    for (int i = 0; i < count; i++)
    {
        array[i].Ticketid = temp->getTicketId();
        array[i].CustomerName = temp->getCustomerName();
        array[i].Priority = temp->getPriorityint();
        array[i].Description = temp->getDescription();
        array[i].CreationTime = temp->getCreationTime();
        array[i].Status = temp->getStatus();
        temp = temp->Next;
    }

    if (line == "BubbleSort")
    {
        bubbleSortForCreationTime(array, count);
    }
    else if (line == "SelectionSort")
    {
        selectionSortForCreationTime(array, count);
    }
    else if (line == "InsertionSort")
    {
        insertionSortForCreationTime(array, count);
    }
    else if (line == "QuickSort")
    {
        quickSortForCreationTime(array, 0, count - 1);
    }
    else if (line == "MergeSort")
    {
        mergeSortForCreationTime(array, 0, count - 1);
    }

    else
    {
        cout << "Invalid sorting method" << endl;
    }

    startData = new Ticket(array[0].Ticketid, array[0].CustomerName, array[0].Priority, array[0].Description, array[0].CreationTime);
    Ticket *current = startData;
    for (int i = 1; i < count; i++)
    {
        Ticket *newTicket = new Ticket(array[i].Ticketid, array[i].CustomerName, array[i].Priority, array[i].Description, array[i].CreationTime);
        current->Next = newTicket;
        current = newTicket;
    }
}

void sortbyCustomerName(string line)
{
    ticket *array = new ticket[count + 1];
    Ticket *temp = startData;
    for (int i = 0; i < count; i++)
    {
        array[i].Ticketid = temp->getTicketId();
        array[i].CustomerName = temp->getCustomerName();
        array[i].Priority = temp->getPriorityint();
        array[i].Description = temp->getDescription();
        array[i].CreationTime = temp->getCreationTime();
        array[i].Status = temp->getStatus();
        temp = temp->Next;
    }

    if (line == "BubbleSort")
    {
        bubbleSortForCustumerName(array, count);
    }
    else if (line == "SelectionSort")
    {
        selectionSortForCustumerName(array, count);
    }
    else if (line == "InsertionSort")
    {
        insertionSortForCustumerName(array, count);
    }
    else if (line == "QuickSort")
    {
        quickSortForCustumerName(array, 0, count - 1);
    }
    else if (line == "MergeSort")
    {
        mergeSortForCustumerName(array, 0, count - 1);
    }

    else
    {
        cout << "Invalid sorting method" << endl;
    }

    startData = new Ticket(array[0].Ticketid, array[0].CustomerName, array[0].Priority, array[0].Description, array[0].CreationTime);
    Ticket *current = startData;
    for (int i = 1; i < count; i++)
    {
        Ticket *newTicket = new Ticket(array[i].Ticketid, array[i].CustomerName, array[i].Priority, array[i].Description, array[i].CreationTime);
        current->Next = newTicket;
        current = newTicket;
    }
}
};

class Agent {
    public:
    int AgentId;
    string AgentName;
    Ticket *Assignedticket;
    int currTicketCount;
    bool Available;

Agent(string name, int id) : AgentId(id), AgentName(name), Assignedticket(NULL), currTicketCount(0), Available(true) {}
Agent() : currTicketCount(0) {}
int getEmptySlots()
{
    return 5 - currTicketCount;
}

void solveTicket(ServiceRequest &onestop, Ticket *selectedTicket)
{
    cout << "Working on Ticket ID: " << selectedTicket->getTicketId() << endl;
    Ticket *mainListTicket = onestop.findTicketById(selectedTicket->getTicketId());
    if (mainListTicket != nullptr)
    {
        mainListTicket->closeTicket(); // Update status to "closed" in startData
    }
    selectedTicket->closeTicket();
    onestop.removefromPendingTicket(selectedTicket->getTicketId());
    onestop.pushinLOG(selectedTicket);
}

void viewAgent()
{
    cout << "Agent ID: " << AgentId << endl;
    cout << "Agent Name: " << AgentName << endl;
    cout << "Current Ticket Count: " << currTicketCount << endl;
    cout << "Available: " << (Available ? "Yes" : "No") << endl;

    // Check if the agent has any assigned tickets
    if (Assignedticket == nullptr)
    {
        cout << "No tickets assigned to this agent.\n";
        return;
    }

    Ticket *temp = Assignedticket;
    int ticketCounter = 0; // Keep track of tickets in case of a linked list

    // Iterate through the linked list of tickets if Assignedticket is a list head
    while (temp != nullptr && ticketCounter < currTicketCount)
    {
        cout << "Ticket ID: " << temp->getTicketId() << endl;
        temp = temp->Next;
        ticketCounter++;
    }
}

void addTicket(Ticket *newTicket)
{
    if (currTicketCount < 5)
    {                              // Check if the agent can take more tickets
        newTicket->Next = nullptr; // Ensure the new ticket is properly terminated

        // If this is the first ticket, assign it directly
        if (Assignedticket == nullptr)
        {
            Assignedticket = newTicket;
        }
        else
        {
            // Traverse to the end of the assigned tickets list
            Ticket *temp = Assignedticket;
            while (temp->Next != nullptr)
            {
                temp = temp->Next;
            }
            temp->Next = newTicket; // Append the new ticket
        }

        currTicketCount++; // Increment the count of assigned tickets
        // Update availability based on ticket count
        Available = (currTicketCount < 5);
    }
    else
    {
        cout << "Agent " << AgentName << " cannot take more tickets.\n";
    }
}

};
class AgentManagement {
    Agent *Agents;
    int AgentCount;
    ServiceRequest &OneStop;

public:

    AgentManagement(ServiceRequest &serviceReq) : Agents(NULL), AgentCount(0), OneStop(serviceReq) {}

    void reportOpenTickets()
    {
        OneStop.ViewPendingQueue();
    }

    void  reportTicketResolutionHistory()
    {
        OneStop.DisplayRecentLogs();
    }
    void  reportAgentLoad()
    {
        cout << "\t\t\t\tAGENT LOAD\n";
        for (int i = 0; i < AgentCount; i++)
        {
            Agents[i].viewAgent();
            cout << endl
                 << endl;
        }
    }

    void resolveTicket()
    {
        int id;
        cout << "Enter Agent ID :";
        cin >> id;
        int agent;

        for (int i = 0; i < AgentCount; i++)
        {
            if (id == Agents[i].AgentId)
            {
                agent = i;
                break;
            }

            if (i == AgentCount - 1)
            {
                cout << "Agent ID not found\n";
                return;
            }
        }

        int ticketId;
        cout << "Enter Ticket ID: ";
        cin >> ticketId;

        for (int i = 0; i < Agents[agent].currTicketCount; i++)
        {
            if (Agents[agent].Assignedticket->getTicketId() == ticketId)
            {
                Agents[agent].solveTicket(OneStop, Agents[agent].Assignedticket);
                Agents[agent].Assignedticket = Agents[agent].Assignedticket->Next;
                Agents[agent].currTicketCount--;
                Agents[agent].Available = (Agents[agent].currTicketCount < 5);
                return;
            }
        }
    }

    void addAgent(Agent agent)
    {
        Agent *temp = new Agent[AgentCount + 1];
        for (int i = 0; i < AgentCount; i++)
        {
            temp[i] = Agents[i];
        }
        temp[AgentCount] = agent;
        delete[] Agents;
        Agents = temp;
        cout << "Agent ID " << agent.AgentId << " added successfully in agents list.\n";
        AgentCount++;
    }

    void assignTicketToAgent()
    {
        Ticket *highestPriorityTicket = OneStop.getPendingTickets();

        if (highestPriorityTicket == nullptr)
        {
            return;
        }

        int maxEmptySlots = -1;
        Agent *selectedAgent = nullptr;

        // Find the agent with the most empty slots who is available
        for (int i = 0; i < AgentCount; i++)
        {
            if (Agents[i].Available && Agents[i].getEmptySlots() > maxEmptySlots)
            {
                maxEmptySlots = Agents[i].getEmptySlots();
                selectedAgent = &Agents[i];
            }
        }

        // Assign the ticket if a suitable agent is found
        if (selectedAgent != nullptr)
        {
            selectedAgent->addTicket(highestPriorityTicket);
            cout << "Ticket " << highestPriorityTicket->getTicketId() << " assigned to Agent " << selectedAgent->AgentName << ".\n";
        }
        else
        {
            cout << "No available agent to assign the ticket.\n";
        }
    }	
};



void adminMenu(AgentManagement &agentManagement) {
    while (true) {
         // Clear screen
        cout << "Enter your choice: " << endl
             << "1. Add Agent" << endl
             << "2. Assign Tickets" << endl
             << "3. Display Info of Agents" << endl
             << "4. Resolve Ticket" << endl
             << "5. Report Open Tickets" << endl
             << "6. Report Agent Ticket Load" << endl
             << "7. Report Ticket Resolution History" << endl
             << "8. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            string name;
            int id;
            cout << "Enter Agent Name: ";
            cin >> name;
            cout << "Enter Agent ID: ";
            cin >> id;
            Agent newAgent(name, id);

            auto start_quick = high_resolution_clock::now();
            agentManagement.addAgent(newAgent);
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            
            cout << "Time taken to add agent: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 2) {
            auto start_quick = high_resolution_clock::now();
            agentManagement.assignTicketToAgent();
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to assign tickets: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 3) {
            auto start_quick = high_resolution_clock::now();
            agentManagement.reportAgentLoad();
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to display agent info: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 4) {
            auto start_quick = high_resolution_clock::now();
            agentManagement.resolveTicket();
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to resolve ticket: " << duration_quick.count() << " milliseconds." << endl;
                    }
        else if (choice == 5) {
            // Report Open Tickets
            auto start_quick = high_resolution_clock::now();
            agentManagement.reportOpenTickets(); // Assuming this function exists in your AgentManagement class
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to report open tickets: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 6) {
            // Report Agent Ticket Load
            auto start_quick = high_resolution_clock::now();
            agentManagement.reportAgentLoad(); // Assuming this function exists in your AgentManagement class
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to report agent ticket load: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 7) {
            // Report Ticket Resolution History
            auto start_quick = high_resolution_clock::now();
            agentManagement.reportTicketResolutionHistory(); // Assuming this function exists in your AgentManagement class
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to report ticket resolution history: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 8) {
            break; // Exit admin menu
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
}

void userMenu(ServiceRequest &serviceRequest) {
    while (true) {
         // Clear screen
        cout << "Enter your choice: " << endl
             << "1. Add Ticket" << endl
             << "2. Display Tickets" << endl
             << "3. Search Ticket" << endl
             << "4. Sort Tickets" << endl
             << "5. View Pending Queue" << endl
             << "6. View Recent Logs" << endl
             << "7. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            int id, priority;
            string name, description;
            cout << "Enter Ticket ID: ";
            cin >> id;
            cout << "Enter Customer Name: ";
            cin >> name;
            cout << "Enter Priority: ";
            cin >> priority;
            cout << "Enter Description: ";
            cin.ignore();              // Clear newline from buffer
            getline(cin, description); // Read description including spaces

            Ticket *newTicket = new Ticket(id, name, priority, description, time(0));

            auto start_quick = high_resolution_clock::now();
            serviceRequest.AddinAllTicket(newTicket);
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to add ticket: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 2) {
            auto start_quick = high_resolution_clock::now();
            serviceRequest.DisplayTickets();
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to display tickets: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 3) {
            auto start_quick = high_resolution_clock::now();
            serviceRequest.SearchTicket();
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to search ticket: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 4) {
            auto start_quick = high_resolution_clock::now();
            serviceRequest.SortsTicket();
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to sort tickets: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 5) {
            auto start_quick = high_resolution_clock::now();
            serviceRequest.ViewPendingQueue();
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to view pending queue: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 6) {
            auto start_quick = high_resolution_clock::now();
            serviceRequest.DisplayRecentLogs();
            auto stop_quick = high_resolution_clock::now();
            auto duration_quick = duration_cast<milliseconds>(stop_quick - start_quick);

            cout << "Time taken to display recent logs: " << duration_quick.count() << " milliseconds." << endl;
            
        }
        else if (choice == 7) {
            break; // Exit user menu
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
}


int main() {
    ServiceRequest serviceRequest; // Create an instance of ServiceRequest
    AgentManagement agentManagement(serviceRequest); // Create an instance of AgentManagement
        
    while (true) {
        cout << "Welcome to the One Stop Management System!" << endl;
        cout << "Select User Type: " << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Exit" << endl;
        
        int userType;
        cin >> userType;

        if (userType == 1) {
            adminMenu(agentManagement); // Call the admin menu function
        } else if (userType == 2) {
            userMenu(serviceRequest); // Call the user menu function
        } else if (userType == 3) {
            cout << "Exiting the program. Goodbye!" << endl;
            break; // Exit the loop and program
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0; // Return success
}