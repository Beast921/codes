#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

bool isValidString(string str){
    int c=0;
    for(int i=0;i<str.length();++i){
        if(str[i]=='(')
            c++;
        else if(str[i]==')')
            c--;
        if(c<0)
            return false;
    }
    return c==0;
}

void removeParenthesis(string str){
    if(str.empty())
        return;
    unordered_set<string> visit;
    queue<string> q;
    string t;
    bool level;
    q.push(str);
    visit.insert(str);
    while(!q.empty()){
        str = q.front();
        q.pop();
        if(isValidString(str)){
            cout<<str<<endl;
            level = true;
        }
        if(level)
            continue;
        for(int i=0;i<str.length();++i){
            if(str[i]!='(' && str[i]!=')')
                continue;
            t = str.substr(0,i) + str.substr(i+1);
            if(visit.find(t) == visit.end()){
                q.push(t);
                visit.insert(t);
            }
        }
    }
}

int main(){
    string s1 = "()())()";
    removeParenthesis(s1);
    s1 = "()v)";
    removeParenthesis(s1);
    return 0;
}