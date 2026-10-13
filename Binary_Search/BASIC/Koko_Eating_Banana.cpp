#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int ans=INT_MIN;
    for(int i=0;i<piles.size();i++) {
        ans=max(ans,piles[i]);
    }
    int l=1;
    int r=ans;
    ans=INT_MAX;
    while(l<=r) {
        int m=l+(r-l)/2;
        int c=0;
        for(int i=0;i<piles.size();i++) {
            c+=piles[i]/m;
            if(piles[i]%m!=0) {
                c++;
            }
        }
        if(c<=h) {
            ans=min(ans,m);
            r=m-1;
        } else {
            l=m+1;
        }
    }
    return ans;
}

int main() {
    int n,h;
    cin>>n>>h;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<minEatingSpeed(v,h)<<endl;
}