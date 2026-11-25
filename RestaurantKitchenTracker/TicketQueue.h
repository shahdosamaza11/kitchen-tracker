#pragma once
#include "Ticket.h"

// node of the queue
struct QueueNode {
    Ticket* ticket;
    QueueNode* next;

    QueueNode(Ticket* ticket) {
        this->ticket = ticket;
        next = NULL;
    }
};

// Queue (FIFO) using linked list - tickets awaiting preparation
class TicketQueue {
private:
    QueueNode* front;
    QueueNode* rear;
    int count;

public:
    TicketQueue();
    bool isEmpty();
    int size();
    void enqueue(Ticket* t);
    Ticket* dequeue();
    Ticket* peek();
    Ticket* getRear();
    void display();
};
