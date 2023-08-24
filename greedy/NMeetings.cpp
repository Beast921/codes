#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second || a.second==b.second && a.first<b.first;
}

class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        int t = -1, c = 0;
        vector<pair<int, int>> v;
        for(int i=0;i<n;++i)
            v.push_back({start[i], end[i]});
        sort(v.begin(), v.end(), cmp);
        for(auto p: v){
            if(p.second>t){
                c++;
                t = p.first;
            }
        }
        return c;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}