#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *head = nullptr;
    Node *temp = nullptr;

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        Node *newNode = new Node;

        cin >> newNode->data;
        newNode->next = nullptr;

        if(head == nullptr)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    int target, newValue;

    cout << "Enter value before which to insert: ";
    cin >> target;

    cout << "Enter new value: ";
    cin >> newValue;

    Node *current = head;
    Node *previous = nullptr;

    while(current != nullptr && current->data != target)
    {
        previous = current;
        current = current->next;
    }

    if(current == nullptr)
    {
        cout << "Value not found";
        return 0;
    }

    Node *newNode = new Node;
    newNode->data = newValue;

    if(previous == nullptr)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        previous->next = newNode;
        newNode->next = current;
    }

    cout << "Updated List: ";

    current = head;

    while(current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}