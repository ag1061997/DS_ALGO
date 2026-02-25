#include <bits/stdc++.h>
using namespace std;

long long zeroFilledSubarray(vector<int>& nums) {
    long long ans=0;
    long long c=0;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]==0) {
            c++;
        } else {
            ans+=c*(c+1)/2;
            c=0;
        }
    }
    ans+=c*(c+1)/2;
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<zeroFilledSubarray(v)<<endl;
    return 0;
}