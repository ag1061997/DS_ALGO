#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    vector<pair<int,char> > v(256);
    for(int i=0;i<256;i++) {
        v[i]=make_pair(0,(int)i);
    }
    for(int i=0;i<s.size();i++) {
        v[(int)s[i]].first++;
    }
    sort(v.begin(),v.end());
    int k=0;
    for(int i=255;i>=0;i--) {
        for(int j=0;j<v[i].first;j++) {
            s[k++]=v[i].second;
        }
        if(k==s.size()) {
            break;
        }
    }
    return s;
}

int main() {
    string s;
    cin>>s;
    cout<<frequencySort(s)<<endl;
    return 0;
}