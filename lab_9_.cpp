// Implement single linked list: 
// a. Create a single linked list. 
// b. Count number of nodes. 
// c. Traverse the linked list. 

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

int count_nodes(Node* head){
    int count = 0;
    Node *temp = head;
    while(temp){
      count++;
      temp = temp->next;
    }
    return count;
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
    
    Node *head = create_linked_list();
    cout << "Number of nodes in linked list is: " << count_nodes(head) << endl;
    traverse_linked_list(head);

    return 0;
}