#include "TicketQueue.h"

TicketQueue::TicketQueue() {
    front = NULL;
    rear = NULL;
    count = 0;
}

// O(1)
bool TicketQueue::isEmpty() {
    if (front == NULL)
        return true;
    else
        return false;
}

// O(1)
int TicketQueue::size() {
    return count;
}

// add a ticket at the rear - O(1)
void TicketQueue::enqueue(Ticket* t) {
    QueueNode* newNode = new QueueNode(t);
    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

// remove the ticket at the front - O(1)
Ticket* TicketQueue::dequeue() {
    if (front == NULL) {
        cout << "  ! Queue Underflow: no tickets waiting." << endl;
        return NULL;
    }
    QueueNode* temp = front;
    Ticket* t = temp->ticket;
    front = front->next;

    // the queue became empty
    if (front == NULL)
        rear = NULL;

    delete temp;
    count--;
    return t;
}

// get the front ticket without removing it - O(1)
Ticket* TicketQueue::peek() {
    if (front == NULL) {
        cout << "  The queue is empty." << endl;
        return NULL;
    }
    return front->ticket;
}

// get the rear ticket - O(1)
Ticket* TicketQueue::getRear() {
    if (rear == NULL)
        return NULL;
    return rear->ticket;
}

// display tickets from front to rear - O(n)
void TicketQueue::display() {
    if (front == NULL) {
        cout << "  No tickets are waiting. The kitchen is clear!" << endl;
        return;
    }
    printTicketHeader();
    QueueNode* temp = front;
    while (temp != NULL) {
        printTicket(temp->ticket);
        temp = temp->next;
    }
    cout << "  (" << count << " tickets waiting; first row = next to cook)" << endl;
}
