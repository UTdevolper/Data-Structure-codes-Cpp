#include <iostream>
using namespace std;

int main()
{
    int arr[100] = {10, 20, 30, 40};
    int n = 4;
    int value = 25;
    int position = 2;

    for(int i = n; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    n++;

    cout << "Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}