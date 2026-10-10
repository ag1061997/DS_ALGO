#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int n=strs.size();
    int i=0;
    while(true) {
        for(int j=0;j<strs.size();j++) {
            if(i>=strs[j].size()|| (strs[j][i]!=strs[0][i])) {
                return strs[0].substr(0,i);
            }
        }
        i++;
    }
    return "";
}

int main() {
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<longestCommonPrefix(v)<<endl;
    return 0;
}