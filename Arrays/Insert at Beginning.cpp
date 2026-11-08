#include <iostream>
using namespace std;

int main()
{
    int arr[100] = {20, 30, 40, 50};
    int n = 4;
    int value = 15;

    for(int i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
    n++;

    cout << "Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}