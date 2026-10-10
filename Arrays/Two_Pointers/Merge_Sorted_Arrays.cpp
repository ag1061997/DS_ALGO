#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1;
    int j=n-1;
    int k=n+m-1;
    while(i>=0||j>=0) {
        if(i>=0&&j>=0) {
            if(nums2[j]>nums1[i]) {
                nums1[k]=nums2[j];
                j--;
            } else {
                nums1[k]=nums1[i];
                i--;
            }
        } else if(i>=0) {
            nums1[k]=nums1[i];
            i--;
        } else {
            nums1[k]=nums2[j];
            j--;
        }
        k--;
    }
}

int main() {
    int n,m;
    cin>>m>>n;
    vector<int> v1(n+m,0);
    vector<int> v2(n);
    for(int i=0;i<m;i++) {
        cin>>v1[i];
    }
    for(int i=0;i<n;i++) {
        cin>>v2[i];
    }
    merge(v1,m,v2,n);
    for(int i=0;i<n+m;i++) {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    return 0;
}