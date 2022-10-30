#include<iostream>
#include<queue>
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

class compare{
    public:
   bool operator()(Node* first,Node* second){
    return first->data > second->data;
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
}

Node* sortKSortedDll(Node* &head,int k){
    if(head == NULL){
        return head;
    }

    priority_queue<Node*,vector<Node*>,compare>pq;
    
    Node* newHead = NULL;
    Node* curr;

    for(int i = 0; head != NULL && i <= k;i++){
        pq.push(head);
        head = head->next;
    }

    while(!pq.empty()){
     
     if(newHead == NULL){
        newHead = pq.top();
        newHead->prev = NULL;
        curr = newHead;
     }

     else{
         curr->next = pq.top();
         pq.top()->prev = curr;
         curr = pq.top();
     }
     pq.pop();

     if(head != NULL){
        pq.push(head);
        head = head->next;
     }


    }
    curr->next = NULL;

    return newHead;


}

int main(){
    Node* node1 = new Node(56);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAtHead(head,12);
    print(head);
    insertAtHead(head,2);
    print(head);
    insertAtHead(head,6);
    print(head);

    insertAtHead(head,3);
    print(head);

    insertAtTail(tail,8);
    print(head);

    int k;
    cout << "ENTER THE VALUE OF K"<< endl;
    cin >> k;


   Node* ans =  sortKSortedDll(head,k);
    print(ans);
}