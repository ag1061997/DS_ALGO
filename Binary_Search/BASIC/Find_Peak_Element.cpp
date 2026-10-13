#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    int l=0;
    int r=n-1;
    while(l<=r) {
        int m=l+(r-l)/2;
        if((m==0||nums[m-1]<nums[m])&&(m==n-1||nums[m+1]<nums[m])) {
            return m;
        } else if (m>0&&nums[m-1]>=nums[m]) {
            r=m-1;
        } else {
            l=m+1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<findPeakElement(v)<<endl;
}