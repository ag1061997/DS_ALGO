#include <bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    int n=nums.size();
    int i=0;
    int j=i+1;
    while(j<n) {
        if(nums[j]-nums[i]==(j-i)) {
            j++;
        } else {
            if(j-1==i) {
                ans.push_back(to_string(nums[i]));
            } else {
                ans.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
            }
            i=j;
            j=i+1;
        }
    }
    if(i<n) {
        if(n-1==i) {
            ans.push_back(to_string(nums[i]));
        } else {
            ans.push_back(to_string(nums[i])+"->"+to_string(nums[n-1]));
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
    vector<string> ans=summaryRanges(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0; 
}