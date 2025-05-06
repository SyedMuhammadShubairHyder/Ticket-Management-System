#include <iostream>
#include <ctime>
#include "Ticket.h"
using namespace std;

    Ticket::Ticket(int id, string name, int priority, string desc) : Ticketid(id), CustomerName(name), Priority(priority), Description(desc), Status("open"), Next(NULL)
    {
        CreationTime = time(NULL);
    }
    

    // for copy constructor
    Ticket::Ticket(int id, string name, int priority, string desc, time_t creationtime) : Ticketid(id), CustomerName(name), Priority(priority), Description(desc), Status("open"), CreationTime(creationtime), Next(NULL) {}

    int Ticket:: getTicketId()
    {
        return Ticketid;
    }
    string Ticket::getCustomerName()
    {
        return CustomerName;
    }
    int Ticket:: getPriorityint()
    {
        return Priority;
    }

    void Ticket::closeTicket()
    {
        Status = "closed";
        CloseTime = time(NULL);
    }
    string Ticket::getPriority()
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
    string Ticket::getDescription()
    {
        return Description;
    }
    time_t Ticket::getCreationTime()
    {
        return CreationTime;
    }
    string Ticket::getCreationTimeString()
    {
        string ct = ctime(&CreationTime);
        return ct;
    }
    string Ticket::getStatus()
    {
        return Status;
    }

    void Ticket::setStatus(string st)
    {
        Status = st;
    }
    time_t Ticket::getCloseTime()
    {
        return CloseTime;
    }
    string Ticket::getCloseTimeString()
    {
        string ct = ctime(&CloseTime);
        return ct;
    }
   
    void Ticket::viewTicket()
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