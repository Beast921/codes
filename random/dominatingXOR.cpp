#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int l, int r, int mid, long &count) {
    int leftsize = mid - l + 1, rightsize = r - mid;
    int leftarr[leftsize], rightarr[rightsize];
    for(int i=0;i<leftsize;++i)
        leftarr[i] = arr[l+i];
    for(int i=0;i<rightsize;++i)
        rightarr[i] = arr[mid+1+i];
    int currleft = 0, currright = 0, currmerge = l;
    while(currleft<leftsize && currright<rightsize){
        if(leftarr[currleft]>rightarr[currright]){
            count += leftsize - currleft;
            arr[currmerge++] = rightarr[currright++];
        }
        else
            arr[currmerge++] = leftarr[currleft++];
    }
    while(currleft<leftsize){
        arr[currmerge++] = leftarr[currleft++];
    }
    while(currright<rightsize){
        arr[currmerge++] = rightarr[currright++];
    }
}

void mergeSort(vector<int>& arr, int l, int r, long &count) {
    if(l>=r)
        return;
        int mid = (l+r)/2;
    mergeSort(arr, l, mid, count);
    mergeSort(arr, mid+1, r, count);
    merge(arr, l, r, mid, count);
}

// long dominatingXorPairs(vector<int>&a) {
//     long count = 0;
//     // mergeSort(a, 0, a.size()-1, count);
//     // return count;

//     for(int i=0;i<a.size()-1;++i){
//         for(int j=i+1;j<a.size();++j){
//             if((a[i] ^ a[j]) > (a[i] & a[j]))
//                 count++;
//         }
//     }
//     return count;
// }

long dominatingXorPairs(std::vector<int>& a) {
    long count = 0;
    int n = a.size();

    for (int i = 0; i < n - 1; ++i) {
        int xor_result = a[i] ^ a[i + 1];
        int and_result = a[i] & a[i + 1];

        if (xor_result > and_result) {
            count += n - (i + 1);
        }
    }

    return count;
}



int main() {
    vector<int> v = {1,1,5,7};
    cout<<dominatingXorPairs(v);
    return 0;
}