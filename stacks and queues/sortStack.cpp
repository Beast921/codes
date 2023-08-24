#include <bits/stdc++.h> 
using namespace std;

void insert(stack<int>& st, int n) {
	if(st.empty()) {
		st.push(n);
		return;
	}
	int a = st.top();
	if(a<=n) {
		st.push(n);
		return;
	}
	st.pop();
	insert(st, n);
	st.push(a);
}

void sortStack(stack<int> &st) {
	if(st.empty()) return;
	int a = st.top();
	st.pop();
	sortStack(st);
	insert(st, a);
}

int main() {
    stack<int> st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);
    sortStack(st);
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}