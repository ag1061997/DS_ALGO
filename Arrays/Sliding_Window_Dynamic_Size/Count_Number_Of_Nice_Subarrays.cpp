#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int start1=0;
    int start2=0;
    int end1=-1;
    int end2=0;
    int c=0;
    int ans=0;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]&1) {
            c++;
            if(c==1) {
                start2=i;
            }
        }
        if(c==k) {
            if(end1==-1) {
                end1=i;
            }
            end2=i;
        }
        if(c>k) {
            ans=ans+(start2-start1+1)*(end2-end1+1);
            start1=start2+1;
            start2++;
            while((nums[start2]&1)==0) {
                start2++;
            }
            end1=i;
            end2=i;
            c--;
        }
    }
    if(c==k) {
        ans=ans+(start2-start1+1)*(end2-end1+1);
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
    cout<<numberOfSubarrays(v,k)<<endl;
    return 0;
}