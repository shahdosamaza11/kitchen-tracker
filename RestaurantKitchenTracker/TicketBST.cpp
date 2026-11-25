#include "TicketBST.h"

TicketBST::TicketBST() {
    root = NULL;
    count = 0;
}

bool TicketBST::isEmpty() {
    if (root == NULL)
        return true;
    else
        return false;
}

int TicketBST::size() {
    return count;
}

// insert a ticket using recursion - O(log n) on average
BSTNode* TicketBST::insert(BSTNode* node, Ticket* t) {
    // if the tree is empty, return a new node
    if (node == NULL)
        return new BSTNode(t);

    // otherwise, recur down the tree
    if (t->id < node->ticket->id)
        node->left = insert(node->left, t);
    else
        node->right = insert(node->right, t);

    return node;
}

void TicketBST::insert(Ticket* t) {
    root = insert(root, t);
    count++;
}

// search a ticket by id using recursion - O(log n) on average
Ticket* TicketBST::search(BSTNode* node, int id) {
    // node is null -> not found
    if (node == NULL)
        return NULL;

    // node has the id -> found
    if (node->ticket->id == id)
        return node->ticket;

    if (id > node->ticket->id)
        return search(node->right, id);
    else
        return search(node->left, id);
}

Ticket* TicketBST::search(int id) {
    return search(root, id);
}

// inorder traversal (left, node, right) prints tickets sorted by id - O(n)
void TicketBST::inorderTraversal(BSTNode* node) {
    if (node == NULL)
        return;
    inorderTraversal(node->left);
    printTicket(node->ticket);
    inorderTraversal(node->right);
}

void TicketBST::inorderTraversal() {
    if (root == NULL) {
        cout << "  No tickets have been created yet." << endl;
        return;
    }
    printTicketHeader();
    inorderTraversal(root);
    cout << "  (" << count << " tickets, sorted by ID)" << endl;
}

// the minimum id is the leftmost node
Ticket* TicketBST::findMin() {
    if (root == NULL)
        return NULL;
    BSTNode* current = root;
    while (current->left != NULL)
        current = current->left;
    return current->ticket;
}

// the maximum id is the rightmost node
Ticket* TicketBST::findMax() {
    if (root == NULL)
        return NULL;
    BSTNode* current = root;
    while (current->right != NULL)
        current = current->right;
    return current->ticket;
}

// height of the tree = number of levels - O(n)
int TicketBST::getHeight(BSTNode* node) {
    if (node == NULL)
        return 0;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int TicketBST::getHeight() {
    return getHeight(root);
}
