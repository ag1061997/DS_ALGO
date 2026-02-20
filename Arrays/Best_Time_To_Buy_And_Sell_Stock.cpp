#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int x=prices[0];
    int ans=0;
    for(int i=1;i<prices.size();i++) {
        ans=max(ans,prices[i]-x);
        x=min(x,prices[i]);
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
    cout<<maxProfit(v)<<endl;
    return 0;
}