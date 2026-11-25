#include "KitchenTracker.h"

// creates a ticket with two items and adds it to the BST and the queue
void KitchenTracker::addSampleOrder(int id, string customer, int itemId1, int qty1, int itemId2, int qty2) {
    Ticket* t = new Ticket(id, customer);
    addItemToTicket(t, menu.search(itemId1), qty1);
    addItemToTicket(t, menu.search(itemId2), qty2);
    tickets.insert(t);
    pending.enqueue(t);
}

void KitchenTracker::loadSampleData() {
    menu.insertAtEnd(1, "Classic Burger", 8.5, "Main");
    menu.insertAtEnd(2, "Margherita Pizza", 11, "Main");
    menu.insertAtEnd(3, "Caesar Salad", 6.75, "Starter");
    menu.insertAtEnd(4, "French Fries", 3.25, "Side");
    menu.insertAtEnd(5, "Grilled Chicken", 12.4, "Main");
    menu.insertAtEnd(6, "Lemonade", 2.5, "Drink");
    menu.insertAtEnd(7, "Chocolate Cake", 4.9, "Dessert");

    // the ids are not in order so the BST is balanced:
    // root = 200, left = 150, right = 250, left of 150 = 120
    addSampleOrder(200, "Sara Ahmed", 1, 2, 4, 1);
    addSampleOrder(150, "Omar Khaled", 2, 1, 3, 1);
    addSampleOrder(250, "Lina Hassan", 5, 1, 7, 2);
    addSampleOrder(120, "Youssef Ali", 1, 1, 6, 1);

    // cook the first ticket so the stack is not empty
    Ticket* t = pending.dequeue();
    t->status = "Completed";
    completed.push(t);
}

// ---------------- Menu (Linked List) ----------------

void KitchenTracker::showMenu() {
    printTitle("Menu Records (Linked List)");
    menu.display();
}

void KitchenTracker::addMenuItem() {
    printTitle("Add Menu Item");
    cout << "  Item ID: ";
    int id = readInt();
    if (id <= 0) {
        cout << "  ! Invalid ID." << endl;
        return;
    }
    if (menu.search(id) != NULL) {
        cout << "  ! Item ID " << id << " already exists." << endl;
        return;
    }
    cout << "  Name: ";
    string name = readText();
    cout << "  Price: ";
    double price = readDouble();
    if (price <= 0) {
        cout << "  ! Invalid price." << endl;
        return;
    }
    cout << "  Category (e.g. Main, Side, Drink): ";
    string category = readText();

    menu.insertAtEnd(id, name, price, category);
    cout << "  + \"" << name << "\" added to the menu." << endl;
}

void KitchenTracker::removeMenuItem() {
    printTitle("Remove Menu Item");
    if (menu.isEmpty()) {
        cout << "  The menu is empty." << endl;
        return;
    }
    menu.display();
    cout << endl << "  Item ID to remove: ";
    int id = readInt();
    MenuItem* m = menu.search(id);
    if (m == NULL) {
        cout << "  ! No menu item with ID " << id << "." << endl;
        return;
    }
    string name = m->name;
    cout << "  Remove \"" << name << "\"? (y/n): ";
    if (!readYesNo()) {
        cout << "  Cancelled." << endl;
        return;
    }
    menu.deleteItem(id);
    cout << "  - \"" << name << "\" removed." << endl;
}

void KitchenTracker::updateMenuPrice() {
    printTitle("Update Item Price");
    if (menu.isEmpty()) {
        cout << "  The menu is empty." << endl;
        return;
    }
    menu.display();
    cout << endl << "  Item ID: ";
    int id = readInt();
    MenuItem* m = menu.search(id);
    if (m == NULL) {
        cout << "  ! No menu item with ID " << id << "." << endl;
        return;
    }
    cout << "  Current price of " << m->name << ": " << formatPrice(m->price) << endl;
    cout << "  New price: ";
    double price = readDouble();
    if (price <= 0) {
        cout << "  ! Invalid price." << endl;
        return;
    }
    string oldPrice = formatPrice(m->price);
    menu.updatePrice(id, price);
    cout << "  * Price updated: " << oldPrice << " -> " << formatPrice(price) << endl;
}

// ---------------- Orders (Queue + BST) ----------------

void KitchenTracker::placeOrder() {
    printTitle("Place New Order");
    if (menu.isEmpty()) {
        cout << "  ! The menu is empty. Add menu items first." << endl;
        return;
    }

    // the ticket id must be unique (checked with the BST)
    int id;
    do {
        cout << "  Ticket ID (0 = cancel): ";
        id = readInt();
        if (id == 0) {
            cout << "  Order cancelled." << endl;
            return;
        }
        if (id < 0)
            cout << "  ! Invalid ID." << endl;
        else if (tickets.search(id) != NULL)
            cout << "  ! Ticket #" << id << " already exists. Choose another ID." << endl;
    } while (id < 0 || tickets.search(id) != NULL);

    cout << "  Customer name: ";
    string customer = readText();

    Ticket* t = new Ticket(id, customer);
    cout << endl;
    menu.display();
    cout << endl << "  Add items by ID. Enter 0 when the order is complete." << endl;

    int itemId;
    do {
        cout << "  Item ID (0 = done): ";
        itemId = readInt();
        if (itemId != 0) {
            // check the item is on the menu
            MenuItem* m = menu.search(itemId);
            if (m == NULL) {
                cout << "  ! Item " << itemId << " is not on the menu." << endl;
            }
            else {
                cout << "  Quantity of " << m->name << ": ";
                int qty = readInt();
                if (qty <= 0) {
                    cout << "  ! Invalid quantity." << endl;
                }
                else {
                    addItemToTicket(t, m, qty);
                    cout << "  + " << qty << " x " << m->name
                         << "   (running total: " << formatPrice(t->total) << ")" << endl;
                }
            }
        }
    } while (itemId != 0);

    if (t->items == NULL) {
        delete t;
        cout << "  ! No items selected. Order cancelled." << endl;
        return;
    }

    tickets.insert(t);
    pending.enqueue(t);
    cout << endl << "  Ticket created and sent to the kitchen:" << endl;
    printTicketDetails(t);
    cout << "  Position in queue: " << pending.size() << endl;
}

void KitchenTracker::showPending() {
    printTitle("Tickets Awaiting Preparation (Queue)");
    pending.display();
}

void KitchenTracker::showNextTicket() {
    printTitle("Next Ticket To Cook (Queue Front)");
    Ticket* t = pending.peek();
    if (t == NULL)
        return;
    printTicketDetails(t);
    Ticket* last = pending.getRear();
    if (last != t)
        cout << "  Last in line: #" << last->id << " (" << last->customer << ")" << endl;
}

// dequeue from the queue and push to the stack
void KitchenTracker::cookNextTicket() {
    printTitle("Mark Next Ticket as Cooked");
    Ticket* t = pending.dequeue();
    if (t == NULL)
        return;
    t->status = "Completed";
    completed.push(t);
    cout << "  Ticket #" << t->id << " for " << t->customer << " is ready! (Queue -> Stack)" << endl;
    cout << "  Tickets still waiting: " << pending.size() << endl;
}

// ---------------- Completed (Stack) ----------------

void KitchenTracker::showLastCompleted() {
    printTitle("Most Recently Completed (Stack Top)");
    Ticket* t = completed.top();
    if (t != NULL)
        printTicketDetails(t);
}

// pop from the stack and enqueue back to the queue
void KitchenTracker::undoLastCompleted() {
    printTitle("Undo Last Completed Order");
    Ticket* t = completed.top();
    if (t == NULL)
        return;
    cout << "  Last completed: #" << t->id << " (" << t->customer << ")" << endl;
    cout << "  Send it back to the kitchen queue? (y/n): ";
    if (!readYesNo()) {
        cout << "  Cancelled." << endl;
        return;
    }
    completed.pop();
    t->status = "Preparing";
    pending.enqueue(t);
    cout << "  Ticket #" << t->id << " is back in the queue at position "
         << pending.size() << ". (Stack -> Queue)" << endl;
}

void KitchenTracker::showCompletedHistory() {
    printTitle("Completed Orders History (Stack, newest first)");
    completed.display();
}

// ---------------- Lookup (BST) ----------------

void KitchenTracker::searchTicket() {
    printTitle("Search Ticket by ID (BST)");
    if (tickets.isEmpty()) {
        cout << "  No tickets exist yet." << endl;
        return;
    }
    cout << "  Ticket ID: ";
    int id = readInt();
    Ticket* t = tickets.search(id);
    if (t == NULL)
        cout << "  ! Ticket #" << id << " was not found." << endl;
    else
        printTicketDetails(t);
}

void KitchenTracker::showAllTickets() {
    printTitle("All Tickets Sorted by ID (BST In-Order)");
    tickets.inorderTraversal();
}

void KitchenTracker::showSummary() {
    printTitle("Kitchen Summary");
    cout << "  Menu items          : " << menu.size() << endl;
    cout << "  Tickets created     : " << tickets.size() << endl;
    cout << "  Waiting (queue)     : " << pending.size() << endl;
    cout << "  Completed (stack)   : " << completed.size() << endl;
    cout << "  BST height          : " << tickets.getHeight() << endl;
    if (!tickets.isEmpty()) {
        cout << "  Lowest ticket ID    : #" << tickets.findMin()->id << endl;
        cout << "  Highest ticket ID   : #" << tickets.findMax()->id << endl;
    }
}
