#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    vector<vector<int> > ans;
    int n=nums.size();
    for(int i=0;i<n;i++) {
        if(i>0) {
            while(i<n&&nums[i]==nums[i-1]) {
                i++;
            }
        }
        for(int j=i+1;j<n;j++) {
            if(j>i+1) {
                while(j<n&&nums[j]==nums[j-1]) {
                    j++;
                }
            }
            int k=j+1;
            int l=n-1;
            while(k<l) {
                if(nums[i]+nums[j]+nums[k]+nums[l]==target) {
                    vector<int> t(4);
                    t[0]=nums[i];
                    t[1]=nums[j];
                    t[2]=nums[k];
                    t[3]=nums[l];
                    ans.push_back(t);
                    k++;
                    l--;
                    while(k<l&&nums[k]==nums[k-1]) k++;
                    while(l>k&&nums[l]==nums[l+1]) l--;
                } else if(nums[i]+nums[j]+nums[k]+nums[l]<target) {
                    k++;
                    while(k<l&&nums[k]==nums[k-1]) k++;
                } else {
                    l--;
                    while(l>k&&nums[l]==nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main() {
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<vector<int> > ans=fourSum(v,t);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
    }
    return 0;
}