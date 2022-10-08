#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    for(int i=0,j=numbers.size()-1;i<j;){
        if(numbers[i]+numbers[j]==target){
            res.push_back(i+1);
            res.push_back(j+1);
            break;
        }
        if(numbers[i]+numbers[j]<target)
            i++;
        else
            j--;
    }
    return res;
}

int main(){
    vector<int> v={2,7,11,15};
    v=twoSum(v,22);
    for(auto x:v)
        cout<<x<<" ";
}