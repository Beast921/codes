#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool canform(string sk, unordered_map<char, int>& m) {
  unordered_map<char, int> u;
  for(char c: sk)
    if(c!='-')
      u[c]++;
  if(u.size()==m.size())
    return true;
  return false;
}

vector<string> sol(string s, vector<string>& skel) {
  vector<string> res;
  unordered_map<char, int> m;
  for(char c: s)
    m[c]++;
  for(string sk: skel) {
    if(canform(sk, m))
      res.push_back(sk);
  }
  return res;
}

int main() {
  string s="hello";
  vector<string> skel = {"he-lo", "he--o", "-ell-", "hello"};
  skel = sol(s, skel);
  for(auto sk: skel)
    cout << sk << " ";
  return 0;
}