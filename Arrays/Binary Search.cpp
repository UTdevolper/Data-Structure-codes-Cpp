#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int value = 40;

    int low = 0;
    int high = n - 1;
    int position = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == value)
        {
            position = mid;
            break;
        }
        else if(value < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(position != -1)
        cout << "Value found at index " << position;
    else
        cout << "Value not found";

    return 0;
}