#include<iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for(int j=low;j<high;++j){
        if(arr[j]<pivot){
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if(low<high){
        int pi = partition(arr, low, high);
    
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int arr[] = {10,40,30,50,90,20};
    int N = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, N-1);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    return 0;
}