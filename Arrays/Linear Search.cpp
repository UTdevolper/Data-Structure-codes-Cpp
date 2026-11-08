#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int value = 40;
    int position = -1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == value)
        {
            position = i;
            break;
        }
    }

    if(position != -1)
        cout << "Value found at index " << position;
    else
        cout << "Value not found";

    return 0;
}