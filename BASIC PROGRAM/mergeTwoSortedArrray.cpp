#include<iostream>
using namespace std;

void printArr(int arr3[],int n ){
    for(int i = 0 ; i < n; i++){
        cout << arr3[i] << " ";
    }
    cout << endl;
}


void merge(int arr1[],int size1,int arr2[],int size2){
    int arr3[10] = {0};
    int k = 0;


    int i = 0;
    int j = 0;
    while(i < size1 && j < size2){
        if(arr1[i] > arr2[j]){
            arr3[k++] = arr2[j++];
        }
        else{
        arr3[k++] = arr1[i++];
        }
    }
    while(i < size1){
        arr3[k++] = arr1[i++];
    }
    while(j < size2){
        arr3[k++] = arr2[j++];
    }

     printArr(arr3,10);
}


int main(){
    int arr1[5] = {1,3,5,7,9};
    int arr2[5] = {2,4,6,8,10};

    merge(arr1,5,arr2,5);
}