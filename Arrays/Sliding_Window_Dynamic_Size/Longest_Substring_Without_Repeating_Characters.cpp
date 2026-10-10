#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> v(256,0);
    int ans=0;
    int j=0;
    for(int i=0;i<s.size();i++){
        while(v[s[i]]>0) {
            v[(int)s[j]]--;
            j++;
        }
        v[(int)s[i]]++;
        ans=max(ans,i-j+1);
    }
    return ans;
}

int main() {
    string s;
    getline(cin,s);
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}