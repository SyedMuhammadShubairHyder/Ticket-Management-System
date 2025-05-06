#include <iostream>
#include "AgentManegement.h"
using namespace std;

Agent::Agent(string name, int id) : AgentId(id), AgentName(name), Assignedticket(NULL), currTicketCount(0), Available(true) {}
Agent::Agent() : currTicketCount(0) {}
int Agent::getEmptySlots()
{
    return 5 - currTicketCount;
}

void Agent::solveTicket(ServiceRequest &onestop, Ticket *selectedTicket)
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

void Agent::viewAgent()
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

void Agent::addTicket(Ticket *newTicket)
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

   AgentManagement:: AgentManagement(ServiceRequest &serviceReq) : Agents(NULL), AgentCount(0), OneStop(serviceReq) {}

    void AgentManagement::reportOpenTickets()
    {
        OneStop.ViewPendingQueue();
    }

    void AgentManagement:: reportTicketResolutionHistory()
    {
        OneStop.DisplayRecentLogs();
    }
    void AgentManagement:: reportAgentLoad()
    {
        cout << "\t\t\t\tAGENT LOAD\n";
        for (int i = 0; i < AgentCount; i++)
        {
            Agents[i].viewAgent();
            cout << endl
                 << endl;
        }
    }

    void AgentManagement::resolveTicket()
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

    void AgentManagement::addAgent(Agent agent)
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

    void AgentManagement::assignTicketToAgent()
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
