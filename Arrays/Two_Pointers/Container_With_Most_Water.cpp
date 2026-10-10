#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int ans=0;
    int i=0;
    int j=height.size()-1;
    while(i<j) {
        ans=max(ans,(min(height[i],height[j])*(j-i)));
        if(height[i]<=height[j]) {
            i++;
        } else {
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
    cout<<maxArea(v)<<endl;
    return 0;
}