#include <bits/stdc++.h>
using namespace std;

int reverseBits(int n) {
    int ans=0;
    int i=31;
    while(n) {
        ans<<=1;
        if(n&1) {
            ans|=1;
        }
        n>>=1;
        i--;
    }
    while(i>=0) {
        ans<<=1;
        i--;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<reverseBits(n)<<endl;
    return 0;
}