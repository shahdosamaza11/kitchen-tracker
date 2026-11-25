// Restaurant Kitchen Tracker
// Linked List : menu records
// Queue       : tickets awaiting preparation
// Stack       : recent completed orders
// BST         : ticket lookup by ID

#include "KitchenTracker.h"

void printMenu() {
    cout << endl;
    cout << "  ==============================================" << endl;
    cout << "         RESTAURANT KITCHEN TRACKER" << endl;
    cout << "  ==============================================" << endl;
    cout << "   MENU RECORDS (Linked List)" << endl;
    cout << "     1. Display menu" << endl;
    cout << "     2. Add menu item" << endl;
    cout << "     3. Remove menu item" << endl;
    cout << "     4. Update item price" << endl;
    cout << "   ORDERS (Queue)" << endl;
    cout << "     5. Place new order" << endl;
    cout << "     6. View pending tickets" << endl;
    cout << "     7. View next ticket to cook" << endl;
    cout << "     8. Mark next ticket as cooked" << endl;
    cout << "   COMPLETED ORDERS (Stack)" << endl;
    cout << "     9. View last completed order" << endl;
    cout << "    10. Undo last completed order" << endl;
    cout << "    11. View completed history" << endl;
    cout << "   TICKET LOOKUP (BST)" << endl;
    cout << "    12. Search ticket by ID" << endl;
    cout << "    13. List all tickets sorted by ID" << endl;
    cout << "    14. Kitchen summary" << endl;
    cout << "     0. Exit" << endl;
    cout << "  ----------------------------------------------" << endl;
}

int main() {
    KitchenTracker kitchen;
    kitchen.loadSampleData();
    cout << endl << "  Sample data loaded: 7 menu items, 4 tickets (3 waiting, 1 completed)." << endl;

    int choice;
    do {
        printMenu();
        cout << "  Choose an option: ";
        choice = readInt();

        switch (choice) {
        case 1: kitchen.showMenu(); break;
        case 2: kitchen.addMenuItem(); break;
        case 3: kitchen.removeMenuItem(); break;
        case 4: kitchen.updateMenuPrice(); break;
        case 5: kitchen.placeOrder(); break;
        case 6: kitchen.showPending(); break;
        case 7: kitchen.showNextTicket(); break;
        case 8: kitchen.cookNextTicket(); break;
        case 9: kitchen.showLastCompleted(); break;
        case 10: kitchen.undoLastCompleted(); break;
        case 11: kitchen.showCompletedHistory(); break;
        case 12: kitchen.searchTicket(); break;
        case 13: kitchen.showAllTickets(); break;
        case 14: kitchen.showSummary(); break;
        case 0: cout << endl << "  Goodbye! Kitchen closed." << endl; break;
        default: cout << "  Invalid Choice" << endl;
        }

        if (choice != 0)
            pressEnter();
    } while (choice != 0);

    return 0;
}
