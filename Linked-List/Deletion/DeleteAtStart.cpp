#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void display(Node* head)
{
    Node* temp = head;

    while(temp != nullptr)
    {
        cout << temp->data;

        if(temp->next != nullptr)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

void deleteAtStart(Node* &head)
{
    if(head == nullptr)
        return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

int main()
{
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};
    head->next->next->next->next = new Node{50, nullptr};

    deleteAtStart(head);
    display(head);

    deleteAtStart(head);
    display(head);

    return 0;
}
