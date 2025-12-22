// Write a program to implement stack using linked list. 

#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* push(int data,Node* top){
    if(!top){
       return new Node(data);
    }
    Node *temp = new Node(data);
    temp->next = top;
    top = temp;
    return top;
}

Node* pop(Node *top){
    if(!top){
        cout << "Stack Underflow";
    }
    else{
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    return top;
}

int peek(Node *top){
    if(!top){
        return -1;
    }
    return top->data;
}

bool isEmpty(Node *top){
    return top==NULL;
}

int main(){
    Node *top = NULL;
    top = push(5,top);
    top = push(4,top);
    top = push(3,top);
    top = pop(top);
    top = pop(top);
    cout << peek(top) << endl;
    top = push(2,top);
    top = push(1,top);
    cout << peek(top) << endl;
    
    return 0;
}