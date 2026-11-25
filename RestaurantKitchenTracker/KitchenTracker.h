#pragma once
#include "MenuList.h"
#include "TicketQueue.h"
#include "CompletedStack.h"
#include "TicketBST.h"
#include "InputUtils.h"

class KitchenTracker {
private:
    MenuList menu;             // Linked List : menu records
    TicketQueue pending;       // Queue       : tickets awaiting preparation
    CompletedStack completed;  // Stack       : recent completed orders
    TicketBST tickets;         // BST         : ticket lookup by ID

    void addSampleOrder(int id, string customer, int itemId1, int qty1, int itemId2, int qty2);

public:
    void loadSampleData();

    // menu
    void showMenu();
    void addMenuItem();
    void removeMenuItem();
    void updateMenuPrice();

    // queue
    void placeOrder();
    void showPending();
    void showNextTicket();
    void cookNextTicket();

    // stack
    void showLastCompleted();
    void undoLastCompleted();
    void showCompletedHistory();

    // BST
    void searchTicket();
    void showAllTickets();
    void showSummary();
};
