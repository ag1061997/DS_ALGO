#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    mp[0]=1;
    int s=0;
    int ans=0;
    for(int i=0;i<nums.size();i++) {
        s=((s+nums[i])%k+k)%k;
        if(mp.find(s)!=mp.end()) {
            ans+=mp[s];
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
    cout<<subarraysDivByK(v,k)<<endl;
    return 0;
}