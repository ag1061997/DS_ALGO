#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    int s=0;
    while(n!=0) {
        int d=n%10;
        s+=d*d;
        n/=10;
    }
    return s;
}

bool isHappy(int n) {
    int s=n;
    int f=n;
    do {
        s=sum(s);
        f=sum(sum(f));
    } while(s!=f);
    return (s==1);
}

int main() {
    int n;
    cin>>n;
    cout<<isHappy(n)<<endl;
    return 0;
}