#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int columnNumber) {
    string ans="";
    while(columnNumber>0) {
        columnNumber--;
        ans=(char)('A'+(columnNumber%26)) + ans;
        columnNumber/=26;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<convertToTitle(n)<<endl;
    return 0;
}