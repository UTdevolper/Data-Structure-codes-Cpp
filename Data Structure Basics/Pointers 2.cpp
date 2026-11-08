#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;

    int max = *p1;

    if (*p2 > max)
        max = *p2;

    if (*p3 > max)
        max = *p3;

    cout << "Maximum number is: " << max << endl;

    return 0;
}