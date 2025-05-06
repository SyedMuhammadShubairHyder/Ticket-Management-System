#include"OneStopMangement.h"
#include "Sorting&Searching.cpp"
#include "Ticket.cpp"
#include "AgentManegement.cpp"
#include "ServiceRequest.cpp"

using namespace std::chrono; // For high_resolution_clock
using namespace std;
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
    ServiceRequest serviceRequest;
    AgentManagement agentManagement(serviceRequest);
    

    while (true) {
        cout << "Enter your choice: " << endl
             << "1. Admin" << endl
             << "2. User" << endl
             << "3. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            adminMenu(agentManagement);
        }
        else if (choice == 2) {
            userMenu(serviceRequest);
        }
        else if (choice == 3) {
            break; // Exit the program
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}