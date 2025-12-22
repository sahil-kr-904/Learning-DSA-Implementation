// a. a.Insert node in singly linked list from beginning.  
// b. Insert a node at certain position

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

Node *insert_beginning(int data,Node *head){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
}

Node *insert_last(int data,Node *head){
    if(!head){
        return new Node(data);
    }
    Node *temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new Node(data);
    return head;
}

Node* insert_at_position(int pos, int data,Node *head){
    Node *temp = head;
    int size = 0;
    while(temp){
        temp = temp->next;
        size++;
    }
    if(pos>size+1 || pos<=0){
      cout << "Position is not valid\n";
    }
    else if(size==0){
        return new Node(data);
    }
    else if(pos==1){
        temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    else if(pos==size+1){
       temp = head;
       while(temp->next){
          temp = temp->next;
       }
       temp->next = new Node(data);
    }
    else{
       temp = head;
       Node *prev = NULL;
       while(pos!=1){
         prev = temp;
         temp = temp->next;
         pos--;
       }
       prev->next = new Node(data);
       (prev->next)->next = temp;
    }
    return head;
}

void traverse_linked_list(Node* head){
   if(!head){
      cout << "Linked List is empty";
      return;
   }

   Node *temp = head;
   while(temp){
      cout << temp->data << " ";
      if(temp->next){
        cout << "-> ";
      }
      temp = temp->next;
   }
}

int main(){
    
    Node *head = NULL;
    head = insert_beginning(5,head);
    head = insert_beginning(4,head);
    head = insert_beginning(3,head);
    head = insert_last(8,head);
    head = insert_last(9,head);
    head = insert_at_position(1,2,head);
    head = insert_at_position(5,6,head);
    head = insert_at_position(6,7,head);
    head = insert_at_position(9,10,head);
    traverse_linked_list(head);

    return 0;
}