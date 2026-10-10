#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int n=s.size();
    int ans=0;
    int c=0;
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='(') {
            c--;
        } else if(s[i]==')') {
            c++;
        }
        ans=max(ans,c);
    }
    return ans;
}

int main() {
    string s;
    cin>>s;
    cout<<maxDepth(s)<<endl;
    return 0;
}