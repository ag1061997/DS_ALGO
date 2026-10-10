#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    vector<int> ans;
    for(int i=0;i<nums.size();i++) {
        if(mp.find(target-nums[i])!=mp.end()) {
            ans.push_back(mp[target-nums[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[nums[i]]=i;
    }
    return ans;
}

int main() {
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=twoSum(v,t);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}