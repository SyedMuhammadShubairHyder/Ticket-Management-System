#include "ServiceRequest.h"
using namespace std;

ServiceRequest::ServiceRequest() : startData(NULL), pendingTickets(NULL), closedTickets(NULL), count(0) {}

// add a ticket when it is ressolve and it status is closed
void ServiceRequest::pushinLOG(Ticket *newTicket)
{
    newTicket->Next = closedTickets; // Set the new ticket's next to the current top
    closedTickets = newTicket;       // Update the top to the new ticket
    cout << "Ticket with ID " << newTicket->getTicketId() << " added to Resolution log.\n";
}
// Display the recent logs
void ServiceRequest::DisplayRecentLogs()
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
Ticket *ServiceRequest::findTicketById(int id)
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
bool ServiceRequest::SearchTicket()
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
void ServiceRequest::SortsTicket()
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
void ServiceRequest::AddInPendingQueue(Ticket *toAdd)
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
void ServiceRequest::ViewPendingQueue()
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
void ServiceRequest::AddinAllTicket(Ticket *toAdd)
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
void ServiceRequest::removefromAllTicket(int id)
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
void ServiceRequest::removefromPendingTicket(int id)
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
Ticket *ServiceRequest::getPendingTickets()
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
void ServiceRequest::DisplayTickets()
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

bool ServiceRequest::searchbyTicketId(string line)
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

bool ServiceRequest:: searchbyCustumerName(string line)
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

void ServiceRequest::sortbyPrioty(string line)
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

void ServiceRequest:: sortbyCreationTime(string line)
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

void ServiceRequest::sortbyCustomerName(string line)
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
