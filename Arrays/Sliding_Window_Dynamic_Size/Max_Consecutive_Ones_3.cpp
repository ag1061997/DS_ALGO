#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int ans=0;
    int c=0;
    int j=0;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]==1) {
            ans=max(ans,i-j+1);
        } else {
            if(c<k) {
                c++;
                ans=max(ans,i-j+1);
            } else {
                while(j<i&&c==k) {
                    if(nums[j]==0) {
                        c--;
                    }
                    j++;
                }
                if(c==k) {
                    j++;
                } else {
                    ans=max(ans,i-j+1);
                    c++;
                }
            }
        }
    }
    return ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<longestOnes(v,k)<<endl;
    return 0;
}