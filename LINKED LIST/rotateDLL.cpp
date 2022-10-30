#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;


    //constuctor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }


};

void insertAtHead(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail,int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    temp->next = NULL;
}

Node* rotateDLL(Node* &head,int n){
    if(n == 0)
    {
        return head;
    }
    Node* curr = head;
    int count = 1;

   while(count < n && curr != NULL)
   {
     curr = curr->next;
     count++;
   }
   Node* hold = curr;


   while(curr != NULL)
   {
    curr = curr->next;
   }

   curr->next = head;
   head->prev = head;
   head = hold;
   head->prev = NULL;
   hold->next = NULL;

   return head;

}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

    int n;
    cout << "ENTER NO OF ROTATION :-";
    cin >> n;
    Node*ans =  rotateDLL(head,n);
    print(ans);

    


}