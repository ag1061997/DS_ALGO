#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int x=cost[0];
    int y=cost[1];
    for(int i=2;i<cost.size();i++) {
        int t=y;
        y=min(x,y)+cost[i];
        x=t;
    }
    return min(x,y);
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<minCostClimbingStairs(v)<<endl;
    return 0;
}