# 🧾 One-Stop Management System Using Linear Data Structures

![C++](https://img.shields.io/badge/language-C++-blue.svg)
![Status](https://img.shields.io/badge/status-Active-green)
![License](https://img.shields.io/badge/license-MIT-lightgrey)
![Data Structures](https://img.shields.io/badge/data--structures-Arrays%2C%20Linked%20Lists%2C%20Stacks%2C%20Queues-brightgreen)

---

## 🎯 Objective

To design and implement a simplified **One-Stop Management System** that manages student service requests, support agents, and resolution logs using **linear data structures** like arrays, linked lists, stacks, and queues.

---

## 🧩 Features

### 🎟 Ticket Management
- ✅ Add / Remove / Search service requests (tickets)
- 🔍 Sort tickets by:
  - Priority
  - Creation Time
  - Customer Name
- 🏷 Attributes:
  - `Ticket ID`, `Customer Name`, `Priority`, `Description`
  - `Creation Time`, `Close Time`, `Status (Open/Closed)`
- 📦 **Data Structure**: Linked List

### 👨‍💼 Agent Management
- 🧑‍💼 Manage agents for:
  - IT, Admin, Accounts (1 each)
  - Academics (3 agents)
- ⚙️ Agent attributes:
  - `Agent ID`, `Name`, `Assigned Tickets`, `Availability`
- 🤖 Assignment Rules:
  - High-priority tickets are served first
  - Agents with fewer open tickets are prioritized
  - Max 5 tickets per agent → mark unavailable
- 📦 **Data Structure**: Dynamic Array

### 📂 Resolution Logs & Pending Queue
- 📥 **Queue**: Holds incoming tickets (FIFO)
- 📤 **Stack**: Logs recently resolved tickets (LIFO)
- 🛠 Operations:
  - Add tickets to queue
  - Assign and resolve tickets
  - Log resolved tickets
  - Display recent logs
- 📦 **Data Structures**: Stack & Queue

### 📊 Reporting and Analytics
- 📌 **Open Tickets Report**
  - Sort by priority / creation time
- 🧮 **Agent Load Report**
  - Show agents and their ticket counts
- 🧾 **Resolution History**
  - View recent resolved tickets from log
- 📈 Algorithms Used:
  - 🔃 Sorting: Bubble, Insertion, Selection, Merge, Quick Sort
  - 🔎 Searching: Interpolation Search, Bubble Search

---

## ⚙️ Configuration File

- `config.txt`: Define default sorting/searching algorithm
- ⚖️ Smart sorting:
  - If dataset < `threshold`, use **elementary sort**
  - If dataset ≥ `threshold`, use **Merge Sort / Quick Sort**

---

## 📐 Time Complexity & Efficiency

⏱ Every operation logs its time complexity and execution time on-screen for performance analysis and debugging.

---

## 💻 Interface

A simple **Command-Line Interface (CLI)** for:
- Managing tickets
- Assigning and monitoring agents
- Viewing logs and generating reports

---



## ✅ Deliverables

- [x] Fully functional and modular C++ system
- [x] Clear in-line documentation
- [x] CLI interface for management and logs
- [x] Sorting and searching based reports
- [x] Configuration file for flexibility
- [x] Time performance logging for each operation

---

## 🚀 Getting Started

```bash
# Step 1: Clone the repository
git clone https://github.com/yourusername/OneStopSystem.git
cd OneStopSystem/src

# Step 2: Compile the project
g++ *.cpp -o OneStopSystem

# Step 3: Run the program
./OneStopSystem
