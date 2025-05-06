#ifndef ONESTOPMANAGEMENT_H
#define ONESTOPMANAGEMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include "Sorting&Searching.h"
#include "Ticket.h"
#include "AgentManegement.h"
#include "ServiceRequest.h"

using namespace std;

// Function declarations
void adminMenu(AgentManagement &agentManagement);
void userMenu(ServiceRequest &serviceRequest);

#endif // ONESTOPMANAGEMENT_H
