#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int l=0;
    int r=nums.size()-1;
    while(l<=r) {
        int m=l+(r-l)/2;
        if(nums[m]==target) {
            return m;
        } else if(nums[m]<target) {
            l=m+1;
        } else {
            r=m-1;
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