#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
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

    int afterValue, newValue;

    cout << "Insert after value: ";
    cin >> afterValue;

    cout << "Enter new value: ";
    cin >> newValue;

    temp = head;

    while(temp != nullptr && temp->data != afterValue)
        temp = temp->next;

    if(temp == nullptr)
    {
        cout << "Value not found!";
    }
    else
    {
        Node *newNode = new Node;

        newNode->data = newValue;

        newNode->next = temp->next;
        temp->next = newNode;

        temp = head;

        cout << "Updated List: ";

        while(temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    return 0;
}