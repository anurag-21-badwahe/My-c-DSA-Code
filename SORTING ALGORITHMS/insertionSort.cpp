#include<iostream>
using namespace std;

void printArr(int *arr,int size){
    cout <<"PRINTING THE ARRAY"<<endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

void insertionSort(int *arr,int size){
    for(int i = 1; i < size; i++){
        int hold = arr[i];
        int j = i-1;
        while( j >= 0){
            if(arr[j] > hold){
                 arr[j+1] = arr[j];
                j--;
            }
        }
        arr[j+1] = hold;
    }
    printArr(arr,size);

}

// void insertionSort(int *arr,int size){
//     for(int i = 1; i < size; i++){
//         int temp = arr[i];
//         int j = i-1;
//         for(j; j >= 0 ; j--){
//             if(arr[j] > temp){//we are not taking arr[i] here because it is changing.DRY RUN THE CODE THEN YOU WILL GET BETTER UNDERSTANDING OF IT
//                 arr[j+1] = arr[j];
//             }
//          else{
//             break;
//         }
//       }
//        arr[j+1] = temp;
      
//     }
//     printArr(arr,size);
// }





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

    
    insertionSort(arr,n);
}