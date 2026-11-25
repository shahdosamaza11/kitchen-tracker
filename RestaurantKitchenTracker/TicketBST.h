#pragma once
#include "Ticket.h"

// node of BST
struct BSTNode {
    Ticket* ticket;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Ticket* ticket) {
        this->ticket = ticket;
        left = right = NULL;
    }
};

// Binary Search Tree - ticket lookup by ID
class TicketBST {
private:
    BSTNode* root;
    int count;

    BSTNode* insert(BSTNode* node, Ticket* t);
    Ticket* search(BSTNode* node, int id);
    void inorderTraversal(BSTNode* node);
    int getHeight(BSTNode* node);

public:
    TicketBST();
    bool isEmpty();
    int size();
    void insert(Ticket* t);
    Ticket* search(int id);
    void inorderTraversal();
    Ticket* findMin();
    Ticket* findMax();
    int getHeight();
};
