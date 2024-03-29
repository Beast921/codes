#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0;i<n-1;++i){
        int min_idx = i;
        for(int j=i+1;j<n;++j)
            if(arr[j]<arr[min_idx])
                min_idx = j;
        if(min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int N = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}