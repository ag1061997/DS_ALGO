#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    unordered_map<string,int> mp;
    vector<vector<string> > ans;
    vector<int> vis(26,0);
    int c=0;
    for(int i=0;i<strs.size();i++) {
        for(int j=0;j<strs[i].size();j++) {
            vis[strs[i][j]-'a']++;
        }
        string t1="";
        for(int j=0;j<26;j++) {
            t1+="#"+to_string(vis[j]);
            vis[j]=0;
        }
        
        if(mp.find(t1)!=mp.end()) {
            ans[mp[t1]].push_back(strs[i]);
        } else {
            vector<string> v1;
            v1.push_back(strs[i]);
            mp[t1]=c;
            c++;
            ans.push_back(v1);
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<vector<string> > ans=groupAnagrams(v);
    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}