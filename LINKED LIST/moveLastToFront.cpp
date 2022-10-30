#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next; 

//constructure
Node(int data){
    this->data = data;
    this->next = NULL;
   }
};

void insertAtTail(Node* &tail,int d){
    //create a new Node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void print(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void moveElement(Node* &head){

   if(head == NULL || head->next == NULL){
    return;
   }

    Node* temp = head;
    Node* prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->next = head;    

    head = prev;
    print(temp);

    

}

int main(){
    Node* node1 = new Node(1);
    Node* tail = node1;
    Node* head = node1;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);

    print(head);

    moveElement(head);
    
}