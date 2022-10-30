#include<iostream>
using namespace std;
void printArr(int *arr,int size){
    cout <<"PRINTING THE ARRAY"<<endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}
void selectionSort(int *arr,int size){
      
      for(int i = 0; i < size-1; i++){
        int minIndex = i;
        for(int j = i+1; j < size ; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
            swap(arr[minIndex],arr[i]);
        }
      }
      printArr(arr,size); 
}



int main(){
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
    selectionSort(arr,n);
}

