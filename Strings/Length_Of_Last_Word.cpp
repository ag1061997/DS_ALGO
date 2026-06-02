#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
    int ans=0;
    int n=s.size();
    while(n>0&&s[n-1]==' ') {
        n--;
    }
    for(int i=n-1;i>=0;i--) {
        if(s[i]==' ') {
            break;
        }
        ans++;
    }
    return ans;
}

int main() {
    string s;
    getline(cin,s);
    cout<<lengthOfLastWord(s)<<endl;
    return 0;
}