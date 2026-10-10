#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++) {
        if(mp.find(nums[i])!=mp.end()) {
            return true;
        }
        mp[nums[i]]=1;
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<containsDuplicate(v)<<endl;
    return 0;
}