#include "MenuList.h"

MenuList::MenuList() {
    head = NULL;
    count = 0;
}

// O(1)
bool MenuList::isEmpty() {
    if (head == NULL)
        return true;
    else
        return false;
}

// O(1)
int MenuList::size() {
    return count;
}

// insert a new item at the end of the list - O(n)
void MenuList::insertAtEnd(int id, string name, double price, string category) {
    MenuItem* newNode = new MenuItem(id, name, price, category);

    if (head == NULL) {
        head = newNode;
    }
    else {
        // traverse to the last node
        MenuItem* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    count++;
}

// delete the item with the given id - O(n)
bool MenuList::deleteItem(int id) {
    MenuItem* temp = head;
    MenuItem* prev = NULL;

    // the item is the head
    if (temp != NULL && temp->id == id) {
        head = temp->next;
        delete temp;
        count--;
        return true;
    }

    // find the item to be deleted
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // the item is not present
    if (temp == NULL)
        return false;

    // remove the node
    prev->next = temp->next;
    delete temp;
    count--;
    return true;
}

// search for an item by id - O(n)
MenuItem* MenuList::search(int id) {
    MenuItem* temp = head;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// update the price of an item - O(n)
bool MenuList::updatePrice(int id, double newPrice) {
    MenuItem* item = search(id);
    if (item == NULL)
        return false;
    item->price = newPrice;
    return true;
}

// display all items - O(n)
void MenuList::display() {
    if (head == NULL) {
        cout << "  The menu is empty." << endl;
        return;
    }
    cout << "  ";
    printLeft("ID", 6);
    printLeft("Name", 24);
    printLeft("Category", 14);
    printRight("Price", 9);
    cout << endl;
    cout << "  -----------------------------------------------------" << endl;

    MenuItem* temp = head;
    while (temp != NULL) {
        cout << "  ";
        printLeft(to_string(temp->id), 6);
        printLeft(temp->name, 24);
        printLeft(temp->category, 14);
        printRight(formatPrice(temp->price), 9);
        cout << endl;
        temp = temp->next;
    }
    cout << "  (" << count << " items)" << endl;
}
