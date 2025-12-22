// Write a program to implement queue using array.

#include<iostream>
using namespace std;

int front=-1,rear=-1;
int arr[100]; 

bool isEmpty(){
    return front==-1;
}

void enqueue(int data){
    if(isEmpty()){
        arr[0] = data;
        front = rear = 0;
        return;
    }
    else if(rear==(sizeof(arr)/sizeof(arr[0]))-1){
        cout << "Queue Overflow for data " << data << endl;
        return;
    }
    arr[rear+1] = data;
    rear++;
}

int dequeue(){
    if(isEmpty()){
        return -1;
    }

    if(front==rear){
        int value = arr[front];
        front=rear=-1;
        return value;
    }

    int value = arr[front];
    front++;
    return value;
}

int peek(){
    if(isEmpty()){
        return -1;
    }
    return arr[front];
}

void traverse(){
    if(isEmpty()){
        cout << "Queue Underflow" << endl;
        return;
    }
    int temp = front;
    while(temp!=rear+1){
        cout << arr[temp] << " ";
        temp++;
    }
    cout << endl;
}

int main(){
    
    enqueue(5);
    traverse();
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