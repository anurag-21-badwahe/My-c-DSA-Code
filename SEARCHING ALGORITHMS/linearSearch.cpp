#include<iostream>
#include<algorithm>
using namespace std;
void linearSearch(int *arr,int size,int target){
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == target){
            cout << " TARGET FOUND AT INDEX :"<< i+1 << endl;
        }
        if(i == size-1){
            cout << " TARGET NOT FOUND" << endl;
        }
    }
}


int main(){
    int n ;
      cout << "ENTER THE SIZE OF THE ARRAY :"<<endl;
      cin >> n;
      //TAKING INPUT DYNAMICALLY
      int *arr = new int[n];
      cout << "ENTER THE ELEMENT OF ARRAY" <<endl;
      for(int i = 0; i < n; i++){
        cin >> arr[i];
      }
      int target;
      cout << "WHICH ELEMENT YOU WANT TO FIND"<<endl;
      cin >> target;
      linearSearch(arr,n,target);
}