#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void display(Node* head)
{
    while(head != nullptr)
    {
        cout << head->data;

        if(head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

void deleteByValue(Node* &head, int value)
{
    if(head == nullptr)
        return;

    if(head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;

    while(current->next != nullptr &&
          current->next->data != value)
    {
        current = current->next;
    }

    if(current->next == nullptr)
    {
        cout << "Value not found" << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

int main()
{
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};
    head->next->next->next->next = new Node{50, nullptr};

    display(head);

    deleteByValue(head, 30);
    display(head);

    deleteByValue(head, 100);

    return 0;
}