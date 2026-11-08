// DSA Lab 7 - Task 2: Doubly Linked List (product IDs)
// Start: 101 <-> 102 <-> 103 <-> 104 <-> 105
// Insert at start / middle / end, then delete first / middle / last
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int main() {
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    // Putting data
    first->data = 101;
    second->data = 102;
    third->data = 103;
    fourth->data = 104;
    fifth->data = 105;

    // Connecting nodes
    first->prev = nullptr;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->next = nullptr;

    // Head and tail
    Node* head = first;
    Node* tail = fifth;

    // Forward traversal
    cout << "Forward Traversal:\n";
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Backward traversal
    cout << "\nBackward Traversal:\n";
    temp = tail;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
    // Adding 100 at the beginning
    Node* newNode = new Node();
    newNode->data = 100;
    newNode->prev = nullptr;
    newNode->next = head;

    head->prev = newNode;
    head = newNode;

    // Display 100 in the beginning
    cout << "\n Adding 5 in the beginning:\n";
    temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    // Adding 1035 between second and third
    Node* newNode1 = new Node();
    newNode1->data = 1035;

    newNode1->prev = second;
    newNode1->next = third;

    second->next = newNode1;
    third->prev = newNode1;

    // Display 1035 in the middle
    cout << "\n Adding 25 in the middle:\n";
    temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    // Adding 106 at the end
    Node* newNode2 = new Node();
    newNode2->data = 106;
    newNode2->next = nullptr;
    newNode2->prev = tail;

    tail->next = newNode2;
    tail = newNode2;

    // Display 106 in the end
    cout << "\n Adding 60 in the end:\n";
    temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Delete first node
    if (head != nullptr) {
        temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
    }

    cout << "\nAfter deleting first node:\n";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    // Delete last node
    if (tail != nullptr) {
        temp = tail;
        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
    }

    cout << "\nAfter deleting last node:\n";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    // Delete middle node containing 1035
    temp = newNode1;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

    cout << "\nAfter deleting middle node (1035):\n";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    // Display final list
    cout << "\nFinal list:\n";
    temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}