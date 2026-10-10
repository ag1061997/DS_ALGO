#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) {
        return nums[0];
    }

    int x=nums[0];
    int y=0;
    int ans=0;

    for(int i=1;i<n-1;i++) {
        int z=y+nums[i];
        y=max(x,y);
        x=z;
    }
    ans=max(x,y);

    x=nums[1];
    y=0;
    for(int i=2;i<n;i++) {
        int z=y+nums[i];
        y=max(x,y);
        x=z;
    }
    ans=max(x,y);

    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    cout<<rob(v)<<endl;

    return 0;
}