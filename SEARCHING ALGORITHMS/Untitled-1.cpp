#include<iostream>
using namespace std;
int main(){
    int arr[6] = {1,1,2,2,2,1};
    int max = -(2^31);
    int maxi = -1;
    int min = 2^31-1;
    int mini = 5 + 1;

    for(int i = 0; i<5;i++){
        for(int j = i+1; j<6;j++){
            if(arr[i] == arr[j]){
                max = j - i;
                if(max > maxi){
                    maxi = max;
                }
                min = j-i;
                if(min < mini){
                     mini = min;
                }
            }
        }
    }
    cout << "MINIMUM DISTANCE BETWEEM TWO SAME ELEMENT IS :"<< maxi << endl;
    cout << "MINIMUM DISTANCE BETWEEM TWO SAME ELEMENT IS :"<<mini << endl;
}