#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;


    //constuctor
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }


};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    temp->next = NULL;
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
    temp->next->prev = nodeToInsert;
    temp -> next = nodeToInsert;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAtHead(head,12);
    print(head);
    insertAtHead(head,15);
    print(head);
    insertAtHead(head,20);
    print(head);



    insertAtTail(tail,25);
    print(head);

   insertAtTail(tail,5);
    print(head);
    
    insertAtPosition(head,tail,3,22);
    print(head);
    


}