// Delete a node of singly linked list: 
// a. from beginning 
// b. from end 
// c. at certain position 
// d. delete entire list 
// e. Reverse the single linked list 

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

Node* create_linked_list(){
    cout << "Enter datas of int type and enter -1 to exit:\n";
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *curr = head;
    cin >> x;
    while(x!=-1){
       Node *temp = new Node(x);
       curr->next = temp;
       curr = curr->next;
       cin >> x;
    }
    return head;
}

Node* delete_beginning(Node *head){
    if(!head){
        cout << "Linked List is empty";
        return head;
    }

    Node *temp = head;
    head = temp->next;
    delete temp;
    return head;
}

Node* delete_end(Node *head){
    if(!head){
        cout << "Linked List is empty";
        return head;
    }
    else if(!head->next){
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

Node* delete_at_position(int pos,Node *head){
    int size = 0;
    Node* temp = head;

    while(temp){
        size++;
        temp = temp->next;
    }

    if(pos<=0 || pos>size){
        cout << "Position is not valid";
    }
    else if(size==1){
        temp = head;
        head = NULL;
        delete temp;
    }
    else if(pos==1){
        temp = head;
        head = head->next;
        delete temp;
    }
    else{
        temp = head;
        Node *prev = NULL;
        while(pos!=1){
            prev = temp;
            temp = temp->next;
            pos--;
        }
        prev->next = temp->next;
        delete temp;
    }
    return head;
}

Node *delete_list(Node *head){
    if(!head){
        cout << "Linked List is already empty";
    }
    else{
      while(head){
        Node *curr = head;
        head = head->next;
        delete curr;
      }
    }
    return head;
}

Node *reverse_list(Node *head){
    if(!head || !head->next){
       return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *agla = head->next;
    head->next = NULL;
    while(agla){
       prev = curr;
       curr = agla;
       agla = agla->next;
       curr->next = prev;
    }
    head = curr;
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
   cout<<endl;
}

int main(){
    Node *head = create_linked_list();
    traverse_linked_list(head);
    head = reverse_list(head);
    traverse_linked_list(head);
    return 0;
}