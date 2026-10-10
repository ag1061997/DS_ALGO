#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int n=nums.size();
    long long p=0;
    for(int i=0;i<n;i++) {
        p^=nums[i];
    }
    long long diff = p&(-p);           // give the rightmost set bit
    int ans1=0;
    for(int i=0;i<n;i++) {
        if(nums[i]&diff) {
            ans1^=nums[i];
        }
    }
    vector<int> ans(2);
    ans[0]=ans1;
    ans[1]=p^ans1;
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=singleNumber(v);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}