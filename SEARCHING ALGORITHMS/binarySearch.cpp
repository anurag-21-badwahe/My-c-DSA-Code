#include<iostream>
#include<algorithm>
using namespace std;
void binarySearch(int arr[],int size, int target){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;

 while(start <= end){

    if(arr[mid] == target){
        cout << "TARGET FOUND AT INDEX:"<< mid << endl;
        break;
    }
    else if(arr[mid] > target){
        end = mid - 1;
    }
    else{
        start = mid + 1;
    }
     mid = start + (end-start)/2;
  }
  if(start > end)
  cout << "ELEMENT NOT FOUND" << endl;
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
      binarySearch(arr,n,target);
}