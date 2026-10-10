#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> ans(n,1);
    for(int i=1;i<n;i++) {
        ans[i]=ans[i-1]*nums[i-1];
    }
    for(int i=n-2;i>=0;i--) {
        ans[i]*=nums[i+1];
        nums[i]*=nums[i+1];
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
    vector<int> ans=productExceptSelf(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}