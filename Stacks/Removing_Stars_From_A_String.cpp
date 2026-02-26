#include <bits/stdc++.h>
using namespace std;

string removeStars(string s) {
    int j=-1;
    for(int i=0;i<s.size();i++) {
        if(s[i]!='*') {
            s[++j]=s[i];
        } else {
            j--;
        }
    }
    return s.substr(0,j+1);
}

int main() {
    string s;
    cin>>s;
    cout<<removeStars(s)<<endl;
    return 0;
}