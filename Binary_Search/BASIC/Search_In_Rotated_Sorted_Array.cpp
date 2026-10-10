#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int n=nums.size();
    int l=0;
    int r=n-1;
    while(l<=r) {
        int m=l+(r-l)/2;
        if(nums[m]==target) {
            return m;
        } else if(nums[l]<=nums[r]) {
            if(nums[m]<target) {
                l=m+1;
            } else {
                r=m-1;
            }
        } else {
            if((nums[m]>nums[l])) {
                if(target<=nums[r]||target>nums[m]) {
                    l=m+1;
                } else {
                    r=m-1;
                }
            } else {
                if(target>nums[m]&&target<nums[l]) {
                    l=m+1;
                } else {
                    r=m-1;
                }
            }
        }
    }
    return -1;
}

int main() {
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<search(v,t)<<endl;
    return 0;
}