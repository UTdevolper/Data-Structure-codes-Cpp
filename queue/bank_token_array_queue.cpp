#include <iostream>   
using namespace std;

#define SIZE 6

int queue[SIZE];
int front = 0, rear = -1;

bool isEmpty()
{
    return front > rear;
}

bool isFull()
{
    return rear == SIZE - 1;
}

void issueToken(int token)
{
    if (isFull())
    {
        cout << "Waiting room is FULL!" << endl;
        return;
    }
    queue[++rear] = token;
    cout << "Token " << token << " issued." << endl;
}

void serveCustomer()
{
    if (isEmpty())
    {
        cout << "No customer waiting!" << endl;
        return;
    }

    cout << "Serving Token: " << queue[front] << endl;
    front++;

    if (front > rear)
    {
        front = 0;
        rear = -1;
    }
}

void displayQueue()
{
    if (isEmpty())
    {
        cout << "No customers waiting." << endl;
        return;
    }

    cout << "Waiting Customers: ";
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";

    cout << endl;
}
int main()
{
    int choice, token = 1;
    do
    {
        cout << "\n1.Issue Token\n2.Serve Customer\n3.Show Waiting Customers\n4.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            issueToken(token++);
            break;

        case 2:
            serveCustomer();
            break;

        case 3:
            displayQueue();
            break;

        case 4:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid Choice!";
        }
    } while (choice != 4);
    return 0;
}