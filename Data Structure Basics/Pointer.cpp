//<---------------------By UTDevolper-------------------->
#include <iostream>
using namespace std;

int main()
{
    int customer_balance;
    int *ptr;
    int deposit_amount, withdrawal_amount;

    cout << "Enter your initial balance: ";
    cin >> customer_balance;

    ptr = &customer_balance;

    cout << "\nCurrent Balance = " << *ptr << endl;

    cout << "\nEnter deposit amount: ";
    cin >> deposit_amount;

    *ptr = *ptr + deposit_amount;

    cout << "Balance after deposit = " << *ptr << endl;

    cout << "\nEnter withdrawal amount: ";
    cin >> withdrawal_amount;

    if(withdrawal_amount <= *ptr)
    {
        *ptr = *ptr - withdrawal_amount;

        cout << "Remaining Balance = " << *ptr << endl;
        cout << "Withdrawal Successful!" << endl;
    }
    else
    {
        cout << "Withdrawal amount is greater than current balance." << endl;
    }

    return 0;
}