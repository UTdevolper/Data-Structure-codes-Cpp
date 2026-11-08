#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node *head = nullptr, *temp = nullptr;

    for(int i = 0; i < n; i++)
    {
        Node *newNode = new Node;

        cout << "Enter value: ";
        cin >> newNode->data;

        newNode->next = nullptr;

        if(head == nullptr)
        {
            head = newNode;
        }
        else
        {
            temp->next = newNode;
        }

        temp = newNode;
    }

    Node *newNode = new Node;

    cout << "Enter value to insert at beginning: ";
    cin >> newNode->data;

    newNode->next = head;
    head = newNode;

    cout << "Linked List: ";

    temp = head;

    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}