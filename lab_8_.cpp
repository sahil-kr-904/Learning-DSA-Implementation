// Write a program to implement queue using Linked List.

#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next;

    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

Node *front=NULL,*rear=NULL;

bool isEmpty(){
    return front==NULL;
}

void enqueue(int data){
    if(isEmpty()){
       front = new Node(data);
       rear = front;
       return;
    }
    rear->next = new Node(data);
    rear = rear->next;
}

int dequeue(){
    if(isEmpty()){
        return -1;
    }

    if(front==rear){
        Node *temp = front;
        int value = temp->data;
        front=rear=NULL;
        delete temp;
        return value;
    }

    Node *temp = front;
    int value = front->data;
    front = front->next;
    delete temp;
    return value;
}

int peek(){
    if(isEmpty()){
        return -1;
    }
    return front->data;
}

void traverse(){
   if(isEmpty()){
      cout << "Linked List is empty";
      return;
   }

   Node *temp = front;
   while(temp){
      cout << temp->data << " ";
      if(temp->next){
        cout << "-> ";
      }
      temp = temp->next;
   }
   cout << endl;
}

int main(){
    
    enqueue(5);
    enqueue(6);
    enqueue(7);
    traverse();
    dequeue();
    traverse();
    dequeue();
    traverse();
    dequeue();
    traverse();

    return 0;
}