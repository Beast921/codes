#include<iostream>
using namespace std;

void merge(int arr[], int l, int r, int mid) {
    int leftsize = mid - l + 1, rightsize = r - mid;
    int leftarr[leftsize], rightarr[rightsize];
    for(int i=0;i<leftsize;++i)
        leftarr[i] = arr[l+i];
    for(int i=0;i<rightsize;++i)
        rightarr[i] = arr[mid+1+i];
    int currleft = 0, currright = 0, currmerge = l;
    while(currleft<leftsize && currright<rightsize){
        if(leftarr[currleft]<rightarr[currright])
            arr[currmerge] = leftarr[currleft++];
        else
            arr[currmerge] = rightarr[currright++];
        currmerge++;
    }
    while(currleft<leftsize){
        arr[currmerge++] = leftarr[currleft++];
    }
    while(currright<rightsize){
        arr[currmerge++] = rightarr[currright++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l>=r)
        return;
        int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, r, mid);
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int N = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, N-1);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}