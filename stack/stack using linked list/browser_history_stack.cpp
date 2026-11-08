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

// Visit a new page
void push(string page){
    Node* newNode = new Node;

    newNode->data = page;
    newNode->next = top;
    top = newNode;

    cout<<"Visited: "<<page<<endl;
}

// Back button
void pop(){

    if(isEmpty()){
        cout<<"Cannot go back"<<endl;
        return;
    }

    // Cannot remove the last remaining page
    if(top->next == NULL){
        cout<<"Cannot go back"<<endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;

    cout<<"Current page: "<<top->data<<endl;
}

// Current page
void peek(){
    if(isEmpty()){
        cout<<"No page visited"<<endl;
    }
    else{
        cout<<"Current page: "<<top->data<<endl;
    }
}

// Display history
void display(){

    if(isEmpty()){
        cout<<"History is empty"<<endl;
        return;
    }

    Node* current = top;

    cout<<"\nBrowser History:\n";

    while(current != NULL){
        cout<<current->data<<endl;
        current = current->next;
    }
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
    string page;

    do{
        cout<<"\n------Browser Menu------\n";
        cout<<"1. Visit Page\n";
        cout<<"2. Back\n";
        cout<<"3. Current Page\n";
        cout<<"4. History\n";
        cout<<"5. Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                cout<<"Enter page name: ";
                cin>>page;
                push(page);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
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