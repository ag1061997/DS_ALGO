#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int n=nums.size();
    for(int i=0;i<n;i++) {
        mp[nums[i]]++;
    }

    vector<vector<int> > frequency(n+1,vector<int>());
    for(unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
        frequency[it->second].push_back(it->first);
    }

    vector<int> ans;
    for(int i=n;i>=0&&ans.size()<k;i--) {
        for(int j=0;j<frequency[i].size()&&ans.size()<k;j++) {
            ans.push_back(frequency[i][j]);
        }
    }

    return ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=topKFrequent(v,k);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}