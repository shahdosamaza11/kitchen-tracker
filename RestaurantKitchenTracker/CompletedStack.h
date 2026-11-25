#pragma once
#include "Ticket.h"

// node of the stack
struct StackNode {
    Ticket* ticket;
    StackNode* next;

    StackNode(Ticket* ticket) {
        this->ticket = ticket;
        next = NULL;
    }
};

// Stack (LIFO) using linked list - recent completed orders
class CompletedStack {
private:
    StackNode* topNode;
    int count;

public:
    CompletedStack();
    bool isEmpty();
    int size();
    void push(Ticket* t);
    Ticket* pop();
    Ticket* top();
    void display();
};
