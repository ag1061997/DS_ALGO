#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ans=0;
    int x=prices[0];
    for(int i=1;i<prices.size();i++) {
        ans+=max(0,prices[i]-x);
        x=prices[i];
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