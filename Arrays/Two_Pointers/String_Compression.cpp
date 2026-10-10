#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    int n=chars.size();
    int i=0;
    int j=1;
    int c=1;
    while(j<n) {
        while(j<n&&chars[j]==chars[i]) {
            c++;
            j++;
        }
        if(c>1) {
            string s=to_string(c);
            for(int k=0;k<s.size();k++) {
                chars[++i]=s[k];
            }
        }
        if(j<n) {
            swap(chars[++i],chars[j++]);
        }
        c=1;
    }
    return i+1;
}

int main() {
    int n;
    cin>>n;
    vector<char> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    int ans = compress(v);
    for(int i=0;i<ans;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}