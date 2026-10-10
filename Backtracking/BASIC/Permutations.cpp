#include <bits/stdc++.h>
using namespace std;

void find(vector<int>& nums,int &n,int count,vector<vector<int> > &ans,vector<int> t,vector<bool> &vis) {
    if(count==n) {
        ans.push_back(t);
        return;
    }
    for(int i=0;i<n;i++) {
        if(vis[i]==0) {
            vis[i]=1;
            t.push_back(nums[i]);
            find(nums,n,count+1,ans,t,vis);
            t.pop_back();
            vis[i]=0;
        }
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > ans;
    int n=nums.size();
    vector<int> t;
    vector<bool> vis(n,0);
    find(nums,n,0,ans,t,vis);
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<vector<int> > ans=permute(v);
    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}