
//Delete At End Then Middle
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

void deleteAtEnd(Node* &head)
{
    if(head == nullptr)
        return;

    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while(temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

void deleteAtPosition(Node* &head, int position)
{
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < position - 1; i++)
        temp = temp->next;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

int main()
{
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};
    head->next->next->next->next = new Node{50, nullptr};

    deleteAtEnd(head);
    display(head);

    deleteAtPosition(head, 2);
    display(head);

    return 0;
}