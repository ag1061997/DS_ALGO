#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0&&nums[i]==nums[i-1]) {
            continue;
        }
        int j=i+1;
        int k=n-1;
        while(j<k) {
            if(nums[i]+nums[j]+nums[k]==0) {
                vector<int> t(3);
                t[0]=nums[i];
                t[1]=nums[j];
                t[2]=nums[k];
                ans.push_back(t);
                j++;
                while(j<k&&nums[j]==nums[j-1]) {
                    j++;
                }
                k--;
                while(k>j&&nums[k]==nums[k+1]) {
                    k--;
                }
            } else if(nums[i]+nums[j]+nums[k]<0) {
                j++;
                while(j<k&&nums[j]==nums[j-1]) {
                    j++;
                }
            } else {
                k--;
                while(k>j&&nums[k]==nums[k+1]) {
                    k--;
                }
            }
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
    vector<vector<int> > ans=threeSum(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }
    return 0;
}