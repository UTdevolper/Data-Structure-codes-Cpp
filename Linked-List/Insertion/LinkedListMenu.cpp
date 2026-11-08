#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = nullptr;

// Insert at Start
void insertAtStart(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

// Insert at End
void insertAtEnd(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert After a Value
void insertInMiddle(int afterValue, int newValue)
{
    Node* temp = head;

    while(temp != nullptr && temp->data != afterValue)
    {
        temp = temp->next;
    }

    if(temp == nullptr)
    {
        cout << "Value not found!" << endl;
        return;
    }

    Node* newNode = new Node;

    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted successfully.\n";
}

// Display List
void display()
{
    if(head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";

    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert in Middle\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int value;
                cout << "Enter value: ";
                cin >> value;
                insertAtStart(value);
                break;
            }

            case 2:
            {
                int value;
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            }

            case 3:
            {
                int afterValue, newValue;

                cout << "Insert after value: ";
                cin >> afterValue;

                cout << "Enter new value: ";
                cin >> newValue;

                insertInMiddle(afterValue, newValue);
                break;
            }

            case 4:
                display();
                break;

            case 5:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}