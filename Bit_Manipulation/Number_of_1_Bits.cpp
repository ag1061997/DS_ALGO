#include <bits/stdc++.h>
using namespace std;

int hammingWeight(int n) {
    int ans=0;
    while(n) {
        if(n&1) {
            ans++;
        }
        n>>=1;
    }
    return ans;  
}

int main() {
    int n;
    cin>>n;
    cout<<hammingWeight(n)<<endl;
    return 0;
}