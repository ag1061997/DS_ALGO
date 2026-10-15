#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    int t=m+n-2;
    int c=min(m-1,n-1);
    long long ans=1;
    for(int i=1;i<=c;i++) {
        ans=ans*(t-c+i)/i;
    }
    return (int)ans;
}

int main() {
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n)<<endl;
}