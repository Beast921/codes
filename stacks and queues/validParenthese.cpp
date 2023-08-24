#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(char c: s) {
        if(c=='{' || c=='[' || c=='(')
            st.push(c);
        else if(c==')')
            if(st.empty() || st.top()!='(') return false;
            else st.pop();
        else if(c==']')
            if(st.empty() || st.top()!='[') return false;
            else st.pop();
        else if(c=='}')
            if(st.empty() || st.top()!='{') return false;
            else st.pop();
    }
    return st.empty();
}

int main() {
    string s = "{([])}";
    if(isValid(s))
        cout<<"Valid";
    else
        cout<<"Not Valid";
    return 0;
}