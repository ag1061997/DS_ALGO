#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<nums1.size();i++) {
        mp[nums1[i]]++;
    }
    for(int i=0;i<nums2.size();i++) {
        if(mp.find(nums2[i])!=mp.end()) {
            ans.push_back(nums2[i]);
            mp[nums2[i]]--;
            if(mp[nums2[i]]==0) {
                mp.erase(nums2[i]);
            }
        }
    }
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    vector<int> v2(m);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    for(int i=0;i<m;i++) {
        cin>>v2[i];
    }
    vector<int> ans=intersect(v,v2);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}