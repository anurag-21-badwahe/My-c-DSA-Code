#include<iostream>
#include<algorithm>
using namespace std;
void printArr(int *arr,int size){
    cout <<"PRINTING THE ARRAY"<<endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}


void bubbleSort(int arr[],int size){
    //first loop is run for no of round
    for(int i = 0; i < size-1; i++){
        // in bubble sort after every round  we place largest element at the end
        for(int j = 0; j < size-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
     printArr(arr,size);
}

int main(){
      //TAKING INPUT
      int n ;
      cout << "ENTER THE SIZE OF THE ARRAY :"<<endl;
      cin >> n;
      //TAKING INPUT DYNAMICALLY
      int *arr = new int[n];
      for(int i = 0; i < n; i++){
        cin >> arr[i];
      }

      //giving input manully
    // int arr[] = {4,3,5,6,7,86};
    //int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
}