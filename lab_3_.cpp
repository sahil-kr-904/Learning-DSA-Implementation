// Write a program to implement stack using array. 

#include<iostream>
using namespace std;

int top=-1;
int arr[100];

bool isEmpty(){
    return top==-1;
}

void push(int data){
   if(top+1==sizeof(arr)/sizeof(arr[0])){
      cout << "Stck Overflow\n";
      return;
   }
   arr[top+1] = data;
   top++;
}

int pop(){
   if(isEmpty()){
      cout << "Stack Underflow\n";
      return -1;
   }
   int value = arr[top];
   top--;
   return value;
}

int peek(){
    if(isEmpty()){
        return -1;
    }
    return arr[top];
}

void traversal(){
    if(isEmpty()){
        cout << "Stack is empty\n";
        return;
    }

    int temp = top;
    while(temp!=-1){
        cout << arr[temp--] << " ";
    }
    cout << endl;
}

int main(){
    
    push(5);
    traversal();
    push(4);
    push(3);
    traversal();
    push(2);
    push(1);
    traversal();
    pop();
    pop();
    traversal();
    pop();
    pop();
    traversal();
    pop();
    traversal();


    return 0;
}