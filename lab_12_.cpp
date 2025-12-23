// Insert a node in the doubly linked list: 
// a. from beginning 
// b. from end 
// c. at a certain position

#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *prev,*next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

Node *insert_beginning(int data,Node *head){
    if(!head){
        return new Node(data);
    }
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

Node *insert_end(int data,Node *head){
    if(!head){
        return new Node(data);
    }
    Node *temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new Node(data);
    (temp->next)->prev = temp;
    return head;
}

Node *insert_at_position(int pos,int data,Node *head){
    int size = 0;
    Node *temp = head;
    while(temp){
        temp = temp->next;
        size++;
    }

    if(pos<=0 || pos>size+1){
        cout << "Position is not valid";
        return head;
    }

    if(!head){
        return new Node(data);
    }

    if(pos==1){
        return insert_beginning(data,head);
    }
    else if(pos==size+1){
        return insert_end(data,head);
    }

    temp = head;
    Node *prev_ = NULL;
    while(pos!=1){
        prev_ = temp;
        temp = temp->next;
        pos--;
    }

    prev_->next = new Node(data);
    temp->prev = prev_->next;
    (prev_->next)->next = temp;
    (prev_->next)->prev = prev_;
    return head;
}

void traverse_linked_list(Node* head){
   if(!head){
      cout << "Linked List is empty";
      return;
   }

   Node *temp = head;
   cout << "NULL <- ";
   while(temp){
      cout << temp->data << " ";
      if(temp->next){
        cout << "-> <- ";
      }
      else{
        cout << "-> NULL";
      }
      temp = temp->next;
   }
   cout << endl;
}

int main(){

    Node *head = NULL;
    head = insert_beginning(4,head);
    head = insert_beginning(3,head);
    head = insert_beginning(2,head);
    traverse_linked_list(head);
    head = insert_end(7,head);
    head = insert_end(8,head);
    head = insert_end(9,head);
    traverse_linked_list(head);
    head = insert_at_position(4,5,head);
    head = insert_at_position(5,6,head);
    traverse_linked_list(head);
    head = insert_at_position(1,1,head);
    head = insert_at_position(10,10,head);
    traverse_linked_list(head);
    return 0;
}