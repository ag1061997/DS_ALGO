#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int ans=0;
    int n=cardPoints.size();
    int s=0;
    for(int i=0;i<k;i++) {
        s+=cardPoints[i];
    }
    ans=s;
    int c=0;
    while(c<k) {
        s-=cardPoints[k-c-1];
        s+=cardPoints[n-1-c];
        ans=max(ans,s);
        c++;
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
    cout<<maxScore(v,k)<<endl;
    return 0;
}