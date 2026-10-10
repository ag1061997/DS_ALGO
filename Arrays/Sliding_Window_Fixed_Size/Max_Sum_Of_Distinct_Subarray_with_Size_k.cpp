#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    long long int ans=0;
    long long int s=0;
    int c=0;
    for(int i=0;i<nums.size();i++) {
        if(mp.find(nums[i])==mp.end()) {
            c++;
            mp[nums[i]]=1;
            s+=nums[i];
            if(c==k) {
                ans=max(ans,s);
                s-=nums[i-k+1];
                mp.erase(nums[i-k+1]);
                c--;
            }
        } else {
            int j=i-c;
            while(j<i) {
                mp.erase(nums[j]);
                s-=nums[j];
                c--;
                if(nums[j]==nums[i]) {
                    break;
                }
                j++;
            }
            i--;
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
    cout<<maximumSubarraySum(v,k)<<endl;
    return 0;
}