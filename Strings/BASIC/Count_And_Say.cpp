#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    string ans="1";
    string t="";
    for(int i=1;i<n;i++) {
        t.clear();
        int j=1;
        int c=1;
        while(j<ans.size()) {
            if(ans[j-1]==ans[j]) {
                c++;
            } else {
                t=t+to_string(c)+ans.substr(j-1,1);
                c=1;
            }
            j++;
        }
        t=t+to_string(c)+ans.substr(j-1,1);
        ans=t;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<countAndSay(n)<<endl;
}