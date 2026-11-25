#pragma once
#include <iostream>
#include <string>
#include "InputUtils.h"
using namespace std;

// node of the menu linked list
struct MenuItem {
    int id;
    string name;
    double price;
    string category;
    MenuItem* next;

    MenuItem(int id, string name, double price, string category) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->category = category;
        next = NULL;
    }
};

// Singly Linked List of menu items
class MenuList {
private:
    MenuItem* head;
    int count;

public:
    MenuList();
    bool isEmpty();
    int size();
    void insertAtEnd(int id, string name, double price, string category);
    bool deleteItem(int id);
    MenuItem* search(int id);
    bool updatePrice(int id, double newPrice);
    void display();
};
