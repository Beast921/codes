#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i=1;i<n;++i){
        int key = arr[i], j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int N = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}