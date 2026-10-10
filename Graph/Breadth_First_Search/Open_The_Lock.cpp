#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int openLock(vector<string>& deadends, string target) {
    unordered_set<string> s;
    s.insert(deadends.begin(),deadends.end());
    if(s.find("0000")!=s.end()) {
        return -1;
    } 
    if(target=="0000") {
        return 0;
    }
    queue<string> q;
    unordered_set<string> vis;
    q.push("0000");
    vis.insert("0000");
    int ans=0;

    while(!q.empty()) {
        int sz=q.size();
        ans++;
        for(int k=0;k<sz;k++) {
            string cur=q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                for(int j=-1;j<=1;j+=2) {
                    string next=cur;
                    next[i]=(char)((((cur[i]-'0')+j+10)%10)+'0');
                    if(target==next) return ans;
                    if(vis.find(next)==vis.end()&&s.find(next)==s.end()) {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    string s;
    cin>>n>>s;
    vector<string> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<openLock(v,s)<<endl;
}