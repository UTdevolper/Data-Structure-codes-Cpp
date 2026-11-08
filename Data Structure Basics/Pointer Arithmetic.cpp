#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    cout << "Original Array: ";
    for(int i = 0; i < 5; i++)
        cout << *(ptr + i) << " ";

    for(int i = 0; i < 5 / 2; i++)
    {
        int temp = *(ptr + i);
        *(ptr + i) = *(ptr + 4 - i);
        *(ptr + 4 - i) = temp;
    }

    cout << "\nReversed Array: ";
    for(int i = 0; i < 5; i++)
        cout << *(ptr + i) << " ";

    return 0;
}