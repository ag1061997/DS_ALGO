#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans=0;
    int c=0;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]==0)
        {
            c=0;
        } else {
            c++;
        }
        ans=max(ans,c);
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
    cout<<findMaxConsecutiveOnes(v)<<endl;
    return 0;
}