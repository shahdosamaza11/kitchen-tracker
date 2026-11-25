# Restaurant Kitchen Tracker

CS 212 Data Structures project (Project 22), written in C++ with no STL containers.

| Data structure | File | Used for |
|---|---|---|
| Singly Linked List | `MenuList.h/.cpp` | Menu records |
| Queue (FIFO) | `TicketQueue.h/.cpp` | Tickets awaiting preparation |
| Stack (LIFO) | `CompletedStack.h/.cpp` | Recent completed orders |
| Binary Search Tree | `TicketBST.h/.cpp` | Ticket lookup by ID |

Other files: `Ticket.h/.cpp` (the order), `InputUtils.h/.cpp` (input and output helpers),
`KitchenTracker.h/.cpp` (connects the four structures), `main.cpp` (menu loop).

## How to run

**Visual Studio 2022:** open `RestaurantKitchenTracker.sln` and press `Ctrl + F5`.

**g++:**

```bash
g++ -std=c++11 -o kitchen RestaurantKitchenTracker/*.cpp
./kitchen
```

The program starts with sample data: 7 menu items and 4 tickets (3 waiting, 1 completed).
