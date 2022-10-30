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
// destuctor
~Node(){
    int value = this->data;

    if(this->next == NULL){
        delete next;
        this->next = NULL;
    }
    cout << "Memory is free for node with data" << " "<< value << endl;
}

};

void insertAtHead(Node* &head,int d){

    //newNode create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int d){
    //create a new Node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){

    if(position == 1){
        insertAtHead(head,d);
    }
    Node * temp = head;
    int count = 1;
    
    while(count < position -1){
        temp = temp->next;
        count++;
    }

    // inserting at last
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }
    // creating a node to d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &head,int position){
   if(position == 1){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    // memory free of start node because  we allocate memory in head
    delete temp;
   }
   else{
    // deleting any node from middle or last
    Node* curr = head;
    Node* prev = NULL;
    int count = 1;
    while(count < position){
        prev = curr;
        curr = curr->next;
        count++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
   }
}

void print(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    //create a new Node
    Node* node1 = new Node(10);//10 is new Node
   // cout << node1->data<< endl;
    //SOME GRABAGE VALUE WILL BE PRINTED
   // cout << node1->next;
    //address will be printed

    //traverse a linked list
    Node* head = node1;
    Node* tail = node1;
    // print(head);
    // insertAtHead(head,12);
    // print(head);
    // insertAtHead(head,15);
    //  print(head);

     print(head);
     insertAtTail(tail,12);
     print(head);
    insertAtTail(tail,15);
    print(head);

    insertAtPosition(head,tail,3,22);
    print(head);


    deleteNode(head,3);
    print(head);





    return 0;

}