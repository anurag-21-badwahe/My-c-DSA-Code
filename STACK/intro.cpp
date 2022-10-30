#include<iostream>
#include<stack>
using namespace std;

class Stack{
    //properties

    // there is two ways to implement an stack 1st is using array and second using linked list
    

};



int main(){
    //creation opf stack
    stack<int>s;
    s.push(1);
   s.push(2);
    cout<< s.top()<<endl; ;
    //stack has lifo structure
    s.pop();
    cout<< s.top()<<endl;
    cout<<s.empty();// if stack is empty is empty then it will return 1 else 0;



    //IMPLEMENT OF STACK WITHOUT USING STL

    //STEP 1: CREATE A CLASS

}