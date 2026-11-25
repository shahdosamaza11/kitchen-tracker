#include "CompletedStack.h"

CompletedStack::CompletedStack() {
    topNode = NULL;
    count = 0;
}

// O(1)
bool CompletedStack::isEmpty() {
    if (topNode == NULL)
        return true;
    else
        return false;
}

// O(1)
int CompletedStack::size() {
    return count;
}

// add a ticket on top - O(1)
void CompletedStack::push(Ticket* t) {
    StackNode* newNode = new StackNode(t);
    newNode->next = topNode;
    topNode = newNode;
    count++;
}

// remove the top ticket - O(1)
Ticket* CompletedStack::pop() {
    if (topNode == NULL) {
        cout << "  ! Stack Underflow: no completed orders." << endl;
        return NULL;
    }
    StackNode* temp = topNode;
    Ticket* t = temp->ticket;
    topNode = topNode->next;
    delete temp;
    count--;
    return t;
}

// get the top ticket without removing it - O(1)
Ticket* CompletedStack::top() {
    if (topNode == NULL) {
        cout << "  No orders have been completed yet." << endl;
        return NULL;
    }
    return topNode->ticket;
}

// display tickets from top to bottom - O(n)
void CompletedStack::display() {
    if (topNode == NULL) {
        cout << "  No orders have been completed yet." << endl;
        return;
    }
    printTicketHeader();
    StackNode* temp = topNode;
    while (temp != NULL) {
        printTicket(temp->ticket);
        temp = temp->next;
    }
    cout << "  (" << count << " completed; first row = most recent)" << endl;
}
