#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int s=0;
    for(int i=0;i<k;i++) {
        s+=nums[i];
    }
    double ans=(double)s;
    for(int i=k;i<nums.size();i++) {
        s-=nums[i-k];
        s+=nums[i];
        ans=max(ans,(double)s);
    }
    return ans/(double)k;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<findMaxAverage(v,k)<<endl;
    return 0;
}