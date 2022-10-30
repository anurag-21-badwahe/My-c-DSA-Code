#include<iostream>
#include<queue>
using namespace std;
class Node{
 public:
 int data;
 Node* left;
 Node* right;

 //Constructor
 Node(int d){
    this->data = d;
    this->left = NULL;
    this->right = NULL;
   }
};
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child nodes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

Node* insertIntoBst(Node* root,int d){
    if(root == NULL){
       root =  new Node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertIntoBst(root->right,d);
    }
    else{
        root->left = insertIntoBst(root->left,d);
    }
    return root;
}

void takeInput(Node* &root){
    
    int data;
    cin >> data;

    while(data != -1){
       root = insertIntoBst(root,data);
        cin >> data;
    }

}



int main(){
Node* root = NULL;
cout << " Enter data to create BST" << endl;
takeInput(root);

cout << "PRINTING THE DATA"<<endl;
levelOrderTraversal(root);

  return 0;
}