#include<iostream>   
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = NULL;

// Check empty
bool isEmpty(){
    return top == NULL;
}

// Push remainder
void push(int value){

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop remainder
int pop(){

    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }

    Node* temp = top;

    int value = temp->data;

    top = top->next;
    delete temp;

    return value;
}

// Decimal to binary
void decimalToBinary(int num){

    if(num == 0){
        push(0);
    }

    while(num > 0){

        int remainder = num % 2;

        push(remainder);

        num = num / 2;
    }

    cout<<"Binary: ";

    while(!isEmpty()){
        cout<<pop();
    }

    cout<<endl;
}

int main(){

    int num;

    cout<<"Enter decimal number: ";
    cin>>num;

    if(num < 0){
        cout<<"Please enter a non-negative number";
    }
    else{
        decimalToBinary(num);
    }

    return 0;
}