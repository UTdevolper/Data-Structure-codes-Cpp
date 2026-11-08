#include <iostream>   
using namespace std;
struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Check if queue is empty
bool isEmpty()
{
    return front == NULL;
}

// Enqueue
void enqueue(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " added to the queue." << endl;
}

// Dequeue
void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is EMPTY! Nothing to remove." << endl;
        return;
    }

    Node* temp = front;
    cout << temp->data << " removed from the queue." << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

// Peek
void peek()
{
    if (isEmpty())
    {
        cout << "Queue is EMPTY!" << endl;
        return;
    }

    cout << "Front Element: " << front->data << endl;
}

// Display Queue
void display()
{
    if (isEmpty())
    {
        cout << "Queue is EMPTY!" << endl;
        return;
    }

    Node* temp = front;

    cout << "FRONT -> ";

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Function 1: Count Nodes
int countNodes()
{
    int count = 0;
    Node* temp = front;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// Function 2: Display Rear Element
void displayRear()
{
    if (rear == NULL)
    {
        cout << "Queue is EMPTY!" << endl;
        return;
    }

    cout << "Rear Element: " << rear->data << endl;
}

// Function 3: Clear Queue
void clearQueue()
{
    while (front != NULL)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    rear = NULL;

    cout << "Queue cleared successfully!" << endl;
}

int main()
{
    int choice, value;
    do
    {
        cout << "\n********* Linked List Queue ********\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display Queue\n";
        cout << "5. Count Nodes\n";
        cout << "6. Display Rear Element\n";
        cout << "7. Clear Queue\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "Total Nodes in Queue: "
                 << countNodes() << endl;
            break;

        case 6:
            displayRear();
            break;

        case 7:
            clearQueue();
            break;

        case 8:
            cout << "Program Terminated!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}