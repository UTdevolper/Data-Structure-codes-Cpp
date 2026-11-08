#include<iostream>   
#include<string>
using namespace std;

struct Node{
    string data;
    Node* next;
};

Node* top = NULL;

// Check empty
bool isEmpty(){
    return top == NULL;
}

// Type word
void push(string word){

    Node* newNode = new Node;

    newNode->data = word;
    newNode->next = top;
    top = newNode;

    cout<<"Typed: "<<word<<endl;
}

// Undo
void pop(){

    if(isEmpty()){
        cout<<"Nothing to undo"<<endl;
        return;
    }

    Node* temp = top;

    cout<<"Undone: "<<temp->data<<endl;

    top = top->next;
    delete temp;
}

// Last word
void peek(){

    if(isEmpty()){
        cout<<"Editor is empty"<<endl;
    }
    else{
        cout<<"Last word: "<<top->data<<endl;
    }
}

// Count words
int size(){

    int count = 0;
    Node* current = top;

    while(current != NULL){
        count++;
        current = current->next;
    }

    return count;
}

// Free memory
void clearStack(){
    while(!isEmpty()){
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main(){

    int choice;
    string word;

    do{
        cout<<"\n------Text Editor------\n";
        cout<<"1. Type Word\n";
        cout<<"2. Undo\n";
        cout<<"3. Last Word\n";
        cout<<"4. Word Count\n";
        cout<<"5. Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                cout<<"Enter word: ";
                cin>>word;
                push(word);
                break;

            case 2:
                pop();
                cout<<"Count = "<<size()<<endl;
                break;

            case 3:
                peek();
                break;

            case 4:
                cout<<"Word Count = "<<size()<<endl;
                break;

            case 5:
                clearStack();
                cout<<"Exiting...";
                break;

            default:
                cout<<"Invalid choice";
        }

    }while(choice != 5);

    return 0;
}