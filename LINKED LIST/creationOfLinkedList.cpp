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

int main(){
    //create a new Node
    Node* node1 = new Node(10);//10 is new Node
    cout << node1->data << endl;
    //SOME GRABAGE VALUE WILL BE PRINTED
    cout << node1->next;
    //address will be printed

    return 0;

}