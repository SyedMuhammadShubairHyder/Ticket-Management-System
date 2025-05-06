#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Ticket.h" // Make sure you include the Ticket header
#include "Sorting&Searching.h"
class ServiceRequest {
private:
    Ticket* startData;
    int count;
    Ticket* pendingTickets; // priority queue
    Ticket* closedTickets;  // stack

public:
    ServiceRequest();

    // Add a ticket when it is resolved and its status is closed
    void pushinLOG(Ticket* newTicket);
    
    // Display the recent logs
    void DisplayRecentLogs();
    
    // Helper function to find ticket by id
    Ticket* findTicketById(int id);
    
    // To search tickets
    bool SearchTicket();
    
    // To sort tickets
    void SortsTicket();
    
    // Add a ticket to pending tickets (having only open tickets)
    void AddInPendingQueue(Ticket* toAdd);
    
    // View pending queue 
    void ViewPendingQueue();
    
    // Add a ticket in the database (having both closed and open tickets)
    void AddinAllTicket(Ticket* toAdd);
    
    // Remove a ticket by its ID
    void removefromAllTicket(int id);
    
    // Remove a ticket from pending queue
    void removefromPendingTicket(int id);
    
    // Get pending tickets
    Ticket* getPendingTickets();
    
    // Display all tickets in the database
    void DisplayTickets();

private:
    // Private member functions for searching and sorting
    bool searchbyTicketId(std::string line);
    bool searchbyCustumerName(std::string line);
    
    void sortbyPrioty(std::string line);
    void sortbyCreationTime(std::string line);
    void sortbyCustomerName(std::string line);
};

#endif // SERVICEREQUEST_H
