#include<iostream>
using namespace std;
class heap{
public:
  //any random size
  int arr[100];
  int size = 0;
  
  heap(){
    arr[0] = -1;
    size = 0;
  }
};

void heapify(int arr[],int n , int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    int size = n;
    //step 1
    while(size > 1){
        //swap first ans last element;
        swap(arr[1],arr[size--]);

       // put sec.third...so on on its right using heapify function
        heapify(arr,size,1);
        

    }
}

int main(){
    heap h;
    int arr[6] = {-1,54,53,55,52,50};
     int n = 5;
     //WE START COUNTING FROM N/2 BECAUSE WE ARE EGNORING LEAF NODE.
    for(int i = n/2; i > 0; i--) {
        heapify(arr,n,i);
    }
    cout <<"PRINTING THE ARRAY"<<endl;
    for(int i = 1; i <= n;i++){
        cout << arr[i] << " ";
        //TIME COMPLEXITY = O(log);
    }
    cout << endl;



    //HEAP SORT
    heapSort(arr,n);
    cout <<"PRINTING THE ARRAY"<<endl;
    for(int i = 1; i <= n;i++){
        cout << arr[i] << " ";
        //TIME COMPLEXITY = O(nlogn);
    }
    cout << endl;

    return 0;

}