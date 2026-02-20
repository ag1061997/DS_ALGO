#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int x=nums[0];
    int c=1;
    for(int i=1;i<nums.size();i++) {
        if(nums[i]==x) {
            c++;
        } else {
            c--;
        }
        if(c==0) {
            c=1;
            x=nums[i];
        }
    } 
    return x;  
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<majorityElement(v)<<endl;
    return 0;
}