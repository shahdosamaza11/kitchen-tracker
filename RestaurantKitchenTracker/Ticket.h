#pragma once
#include "MenuList.h"

// one item inside a ticket (node of a small linked list)
struct OrderItem {
    int itemId;
    string name;
    double price;
    int quantity;
    OrderItem* next;

    OrderItem(int itemId, string name, double price, int quantity) {
        this->itemId = itemId;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        next = NULL;
    }
};

// a customer order
struct Ticket {
    int id;
    string customer;
    string status;      // "Preparing" or "Completed"
    double total;
    OrderItem* items;   // head of the items list

    Ticket(int id, string customer) {
        this->id = id;
        this->customer = customer;
        status = "Preparing";
        total = 0;
        items = NULL;
    }
};

void addItemToTicket(Ticket* t, MenuItem* m, int quantity);
void printTicketHeader();
void printTicket(Ticket* t);
void printTicketDetails(Ticket* t);
