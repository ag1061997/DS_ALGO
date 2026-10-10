#include <bits/stdc++.h>
using namespace std;

int guess(int n) {
    if(n==5) {
        return 0;
    } else if(n<5) {
        return -1;
    }
    return 1;
}

int guessNumber(int n) {
    int l=1;
    int r=n;
    while(l<=r) {
        int m=l+(r-l)/2;
        if(guess(m)==0) {
            return m;
        } else if(guess(m)<0) {
            r=m-1;
        } else {
            l=m+1;
        }
    }    
    return -1;
}

int main() {
    int n,t;
    cin>>n;
    cout<<guessNumber(n)<<endl;
    return 0;
}