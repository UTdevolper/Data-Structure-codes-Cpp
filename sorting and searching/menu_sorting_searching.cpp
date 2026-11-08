#include<iostream>  //Uzma Tufail  72900
using namespace std;
void Menu(){
    cout<<"\n\n-----Searching and Sorting-----\n";
    cout<<"1) Selection Sort\n";
    cout<<"2) Bubble Sort\n";
    cout<<"3) Insertion Sort\n";
    cout<<"4) Binary Search\n";
    cout<<"5) Exit\n";
}
void data(int arr[],int size){
    cout<<"\n--------:Enter the elements of array:---------\n";
    for(int i=0;i<size;i++){
            cout<<"\nEnter the "<<i+1<<" Element: ";
            cin>>arr[i];
    }
    cout<<"\n<-------Your array include--------->\n";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<"  ";
    }
}
void Selection_Sort(int arr[],int size){
    cout<<"\n==================Selection Sort==============\n";

    for(int i = 0; i < size-1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    cout<<"\n Sorted Array \n";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Bubble_sort(int arr[],int size){
    cout<<"\n==================Bubble Sort==============\n";
        for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout<<"\n Bubble Sorted  Array \n";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

}

void Insertion_sort(int arr[],int size){
    cout<<"\n==================Insertion Sort==============\n";
    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
    cout<<"\n Insertion Sorted  Array \n";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void Binary_search(int arr[],int size){
    cout<<"\n==================Binary search ==============\n";
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;

    int low = 0;
    int high = size - 1;
    int mid;
    bool found=false;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key){
            cout<<"Element found at index: "<<mid<<endl;
            found=true;
            break;
        }

        else if(key > arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    if(found==false){
        cout<<"ELement not found!"<<endl;
    }

}
int main(){
    const int size=10;
    int arr[10];
    data(arr,size);
    int choice;

    do{
        Menu();
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:{
                Selection_Sort(arr,size);
                break;
            }
            case 2:{
             Bubble_sort(arr,size);
                break;
            }
            case 3:{
                Insertion_sort(arr,size);
                break;
            }
            case 4:{
                Selection_Sort(arr,size);
                Binary_search(arr,size);
                break;
            }
            case 5:{
                cout<<"Exiting...";
                break;
            }
            default:{
                cout<<"Invalid choice!";
                break;
            }
        }
    }while(choice!=5);
}