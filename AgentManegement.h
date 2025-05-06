#ifndef AGENT_MANAGEMENT_H
#define AGENT_MANAGEMENT_H

#include <iostream>
#include "ServiceRequest.h" // Include the ServiceRequest header, not .cpp

using namespace std;

class Agent {
    public:
    int AgentId;
    string AgentName;
    Ticket *Assignedticket;
    int currTicketCount;
    bool Available;

    Agent(string name, int id);
    Agent();
    int getEmptySlots();

    void solveTicket(ServiceRequest &onestop, Ticket *selectedTicket);

    void viewAgent();

    void addTicket(Ticket *newTicket);
};

class AgentManagement {
    Agent *Agents;
    int AgentCount;
    ServiceRequest &OneStop;

public:
    AgentManagement(ServiceRequest &serviceReq) ;
    void reportOpenTickets();

    void reportTicketResolutionHistory() ;

    void reportAgentLoad();

    void resolveTicket() ;

    void addAgent(Agent agent) ;
    void assignTicketToAgent() ;
};

#endif // AGENT_MANAGEMENT_H
