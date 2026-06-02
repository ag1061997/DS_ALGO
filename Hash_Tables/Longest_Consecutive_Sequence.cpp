#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> mp;
    for(int i=0;i<nums.size();i++) {
        mp.insert(nums[i]);
    }
    int ans=0;
    int c=0;
    for(int i=0;i<nums.size();i++) {
        c=1;
        if(mp.find(nums[i]-1)==mp.end()) {
            int c1=1;
            while(mp.find(nums[i]+c1)!=mp.end()) {
                c++;
                c1++;
            }
        }
        ans=max(ans,c);
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
    cout<<longestConsecutive(v)<<endl;
    return 0;
}