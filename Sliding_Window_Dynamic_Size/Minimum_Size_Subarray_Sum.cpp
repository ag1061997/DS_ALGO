#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int ans=INT_MAX;
    int s=0;
    int i=0;
    for(int j=0;j<nums.size();j++) {
        s+=nums[j];
        while(s>=target) {
            ans=min(ans,j-i+1);
            s-=nums[i];
            i++;
        }
    }
    if(ans==INT_MAX) {
        return 0;
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
    cout<<minSubArrayLen(k,v)<<endl;
    return 0;
}