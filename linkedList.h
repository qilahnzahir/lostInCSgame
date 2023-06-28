#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "item.h"
using namespace std;

class LinkedList
{
private:
    struct Node {
        Item item;
        Node* next;
    };
    Node* head;

public:
    // constructor
    LinkedList() {
        head = nullptr;
    }

    // destructor
    ~LinkedList();

    // Linked List operations
    void appendNode(const Item&);
    void display() const;
    void deleteNode(const Item&);
    int countIn(const Item&) const;
    void addAllItemsToInventory(LinkedList&);
    Node* getHead()const;
};

LinkedList::~LinkedList() {
    Node* nodePtr = head;
    while (nodePtr != nullptr) {
        Node* nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void LinkedList::appendNode(const Item& item) {
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* nodePtr = head;
        while (nodePtr->next != nullptr) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void LinkedList::deleteNode(const Item& item) {
    Node* nodePtr = head;
    Node* previousNode = nullptr;

    if (head == nullptr) {
        cout << "Linked list is empty. Cannot delete." << endl;
        return;
    }

    if (head->item.getName() == item.getName()) {
        head = head->next;
        delete nodePtr;
        return;
    }

    while (nodePtr != nullptr && nodePtr->item.getName() != item.getName()) {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    if (nodePtr == nullptr) {
        cout << "Item not found in the linked list. Item cannot be used." << endl;
        return;
    }

    previousNode->next = nodePtr->next;
    delete nodePtr;
}
void LinkedList::display() const {
    Node* nodePtr = head;

    if (head == nullptr) {
        cout << "Your inventory is empty." << endl;
        return;
    }

    cout<<endl;
    cout<<"Inventory "<<endl;
    cout<<"--------- "<<endl;

    while (nodePtr != nullptr) {
        cout <<">"<<nodePtr->item.getName()<<endl;
        nodePtr = nodePtr->next;
    }

    cout << endl;
}

int LinkedList::countIn(const Item& item)const{
  Node* nodePtr = head;
    int count = 0;
    while (nodePtr != nullptr) {
        if (nodePtr->item.getName() == item.getName()) {
            count++;
        }
        nodePtr = nodePtr->next;
    }
    return count;
}
void LinkedList::addAllItemsToInventory(LinkedList& inventory)
{
    Node* nodePtr = head;
    while (nodePtr != nullptr)
    {
        inventory.appendNode(nodePtr->item);
        nodePtr = nodePtr->next;
    }
}


#endif
