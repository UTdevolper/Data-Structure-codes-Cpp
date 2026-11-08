#include<iostream> //Uzma Tufail 72900
using namespace std;

const int MAX = 5;
int stk[MAX];
int top = -1;

// Check empty
bool isEmpty(){
    return top == -1;
}

// Check full
bool isFull(){
    return top == MAX-1;
}

// Push
void push(int value){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
        return;
    }

    top++;
    stk[top] = value;
    cout<<value<<" pushed"<<endl;
}

// Pop
void pop(){
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return;
    }

    cout<<"Popped: "<<stk[top]<<endl;
    top--;
}

// Search from top
int search(int x){

    int steps = 1;

    for(int i=top; i>=0; i--){

        if(stk[i] == x){
            return steps;
        }

        steps++;
    }

    return -1;
}

int main(){

    int value;

    cout<<"Enter 5 integers:\n";

    for(int i=0; i<MAX; i++){
        cin>>value;
        push(value);
    }

    // Attempt sixth push
    cout<<"\nEnter sixth value: ";
    cin>>value;
    push(value);

    // Search before removing elements
    int key;

    cout<<"\nEnter value present in stack: ";
    cin>>key;

    int result = search(key);

    if(result == -1)
        cout<<"Value not found\n";
    else
        cout<<"Found at step "<<result
            <<" from top\n";

    cout<<"\nEnter value absent from stack: ";
    cin>>key;

    result = search(key);

    if(result == -1)
        cout<<"Value not found\n";
    else
        cout<<"Found at step "<<result
            <<" from top\n";

    // Remove all five elements
    cout<<"\nPopping all elements:\n";

    for(int i=0; i<MAX; i++){
        pop();
    }

    // Attempt another pop
    pop();

    return 0;
}