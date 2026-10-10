#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int s=0;
    mp[0]=1;
    int ans=0;
    for(int i=0;i<nums.size();i++) {
        s+=nums[i];
        if(mp.find(s-k)!=mp.end()) {
            ans+=mp[s-k];
        }
        mp[s]++;
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
    cout<<subarraySum(v,k)<<endl;
    return 0;
}