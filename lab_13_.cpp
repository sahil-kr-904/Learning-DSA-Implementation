// Delete a node of doubly linked list: 
// a. from beginning 
// b. from end 
// c. at certain position 

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

Node *delete_beginning(Node* head){
    if(!head){
        cout << "Linked List has no element\n";
        return head;
    }
    if(!head->next){
        delete head;
        return NULL;
    }
    Node *temp = head;
    (temp->next)->prev = NULL;
    head = head->next;
    delete temp;
    return head;
}

Node *delete_end(Node* head){
    if(!head){
        cout << "Linked List has no element\n";
        return head;
    }
    if(!head->next){
        delete head;
        return NULL;
    }
    Node *temp = head;
    Node *prev = NULL;
    while(temp->next){
       prev = temp;
       temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    return head;
}

Node *delete_at_poistion(int pos,Node* head){
    int size = 0;
    Node *temp = head;
    while(temp){
        temp = temp->next;
        size++;
    }

    if(pos<=0 || pos>size){
        cout << "Position is not valid";
        return head;
    }

    if(pos==1){
        return delete_beginning(head);
    }
    else if(pos==size){
        return delete_end(head);
    }

    temp = head;
    Node *prev_ = NULL;
    while(pos!=1){
       prev_ = temp;
       temp = temp->next;
       pos--;
    }

    prev_->next = temp->next;
    (temp->next)->prev = prev_;

    delete temp;
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
    for(int i=10; i>0; i--){
        head = insert_beginning(i,head);
    }
    traverse_linked_list(head);
    head = delete_beginning(head);
    head = delete_beginning(head);
    traverse_linked_list(head);
    head = delete_at_poistion(5,head);
    traverse_linked_list(head);
    head = delete_end(head);
    traverse_linked_list(head);
    return 0;
}