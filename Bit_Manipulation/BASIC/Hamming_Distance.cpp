#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
    int z=x^y;
    int ans=0;
    while(z) {
        if(z&1) ans++;
        z>>=1;
    }
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    cout<<hammingDistance(n,m)<<endl;
    return 0; 
}