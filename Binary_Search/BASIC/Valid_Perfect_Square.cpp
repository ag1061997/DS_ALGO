#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num) {
    int l=1;
    int r=num;
    while(l<=r) {
        int m=l+(r-l)/2;
        if((num%m==0)&&m==num/m) {
            return true;
        } else if(m<=num/m) {
            l=m+1;
        } else {
            r=m-1;
        }
    }
    return false;
}

int main() {
    int t;
    cin>>t;
    cout<<isPerfectSquare(t)<<endl;
    return 0;
}