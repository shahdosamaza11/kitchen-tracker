#include "Ticket.h"

// add an item to the ticket (at the end of its items list)
// if the item is already in the ticket, increase its quantity
void addItemToTicket(Ticket* t, MenuItem* m, int quantity) {
    t->total = t->total + m->price * quantity;

    OrderItem* temp = t->items;
    while (temp != NULL) {
        if (temp->itemId == m->id) {
            temp->quantity = temp->quantity + quantity;
            return;
        }
        temp = temp->next;
    }

    OrderItem* newItem = new OrderItem(m->id, m->name, m->price, quantity);
    if (t->items == NULL) {
        t->items = newItem;
    }
    else {
        temp = t->items;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newItem;
    }
}

// column titles for the ticket lists
void printTicketHeader() {
    cout << "  ";
    printLeft("Ticket", 7);
    printLeft("Customer", 16);
    printLeft("Status", 11);
    printRight("Total", 9);
    cout << "   Items" << endl;
    cout << "  ----------------------------------------------------------------------" << endl;
}

// print the ticket in one line
void printTicket(Ticket* t) {
    cout << "  ";
    printLeft("#" + to_string(t->id), 7);
    printLeft(t->customer, 16);
    printLeft(t->status, 11);
    printRight(formatPrice(t->total), 9);
    cout << "   ";

    OrderItem* temp = t->items;
    while (temp != NULL) {
        cout << temp->quantity << "x " << temp->name;
        if (temp->next != NULL)
            cout << ", ";
        temp = temp->next;
    }
    cout << endl;
}

// print the ticket with all its items
void printTicketDetails(Ticket* t) {
    cout << "  +--------------------------------------------------+" << endl;
    cout << "  Ticket ID : " << t->id << endl;
    cout << "  Customer  : " << t->customer << endl;
    cout << "  Status    : " << t->status << endl;
    cout << "  Items     :" << endl;
    OrderItem* temp = t->items;
    while (temp != NULL) {
        cout << "     ";
        printRight(to_string(temp->quantity), 2);
        cout << " x ";
        printLeft(temp->name, 22);
        cout << " @ ";
        printRight(formatPrice(temp->price), 7);
        cout << " = ";
        printRight(formatPrice(temp->price * temp->quantity), 8);
        cout << endl;
        temp = temp->next;
    }
    cout << "  Total     : " << formatPrice(t->total) << endl;
    cout << "  +--------------------------------------------------+" << endl;
}
