#ifndef Ticket_H
#define Ticket_H

#include <iostream>


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
    Ticket(int id, std::string name, int priority, std::string desc) ;
    // for copy constructor
    Ticket(int id,std:: string name, int priority, std::string desc, time_t creationtime);
    int getTicketId();
    std::string getCustomerName();
    int getPriorityint();
    std::string getPriority();
    std::string getDescription();
    time_t getCreationTime();
    time_t getCloseTime();
    std::string getCreationTimeString();
    std::string getStatus();
    std::string getCloseTimeString();
    void closeTicket();
    void setStatus(std::string st);
    void viewTicket();
};

#endif // TICKET_H