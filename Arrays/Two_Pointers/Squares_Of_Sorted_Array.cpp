#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans;
    int i=0;
    while(i<nums.size()&&nums[i]<=0) {
        i++;
    }  
    int j=i-1;
    while(j>=0||i<nums.size()) {
        if(j>=0&&i<nums.size()) {
            if(abs(nums[j])<=nums[i]) {
                ans.push_back(nums[j]*nums[j]);
                j--;
            } else {
                ans.push_back(nums[i]*nums[i]);
                i++;
            }
        } else if(j<0) {
            ans.push_back(nums[i]*nums[i]);
            i++;
        } else {
            ans.push_back(nums[j]*nums[j]);
            j--;
        }
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
    vector<int> ans=sortedSquares(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}