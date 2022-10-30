#include<iostream>
#include<algorithm>
using namespace std;
void printArr(int *arr,int size){
    cout <<"PRINTING THE ARRAY"<<endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

void cyclicSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int current = arr[i];
        if(arr[i] != i){
            swap(arr[current],arr[i]);
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
      cyclicSort(arr,n);
}
