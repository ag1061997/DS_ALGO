#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int x=0;
    int n=nums.size();
    for(int i=0;i<n-1;i++) {
        if(i<=x) {
            x=max(x,i+nums[i]);
        } else {
            return false;
        }
    }
    return (x>=(n-1));  
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<canJump(v)<<endl;
    return 0;
}