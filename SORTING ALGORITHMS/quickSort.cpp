#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{

    int pivot = arr[s];

    // now we count how many element are less than pivot
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);

    // now handle pivot left and right part
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    // do partition
    int p = partition(arr, s, e);

    // sort the left part
    quickSort(arr, s, p - 1);

    // sort the right part
    quickSort(arr, p, e);
}

int main()
{

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

//     int n;
//     cout << "ENTER THE SIZE OF THE ARRAY :-" << endl;
//     cin >> n;
//     int *arr = new int[n];
//     cout << "ENTER THE ELEMENT OF THE ARRAY" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     quickSort(arr, 0, n - 1);

//    for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
}
