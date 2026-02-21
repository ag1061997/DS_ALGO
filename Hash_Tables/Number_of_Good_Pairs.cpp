#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int,int> mp;
    int ans=0;
    for(int i=0;i<nums.size();i++) {
        ans+=mp[nums[i]];
        mp[nums[i]]++;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<numIdenticalPairs(v)<<endl;
    return 0;
}