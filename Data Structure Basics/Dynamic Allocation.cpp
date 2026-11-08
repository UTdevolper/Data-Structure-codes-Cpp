#include <iostream>
#include <string>
using namespace std;

struct Product
{
    string name;
    int code;
    float price;
};

int main()
{
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    Product *products = new Product[n];

    for(int i = 0; i < n; i++)
    {
        cout << "\nProduct " << i + 1 << endl;

        cout << "Enter Name: ";
        cin >> products[i].name;

        cout << "Enter Code: ";
        cin >> products[i].code;

        cout << "Enter Price: ";
        cin >> products[i].price;
    }

    cout << "\n----- Product Details -----\n";

    for(int i = 0; i < n; i++)
    {
        cout << "\nName: " << products[i].name << endl;
        cout << "Code: " << products[i].code << endl;
        cout << "Price: " << products[i].price << endl;
    }

    delete[] products;

    return 0;
}