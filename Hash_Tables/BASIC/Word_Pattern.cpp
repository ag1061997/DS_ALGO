#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string s) {
    vector<string> v1(26,"");
    unordered_map<string,int> mp;
    int i=0;
    int j=0;
    while(i<pattern.size()) {
        int x=pattern[i]-'a';
        i++;
        string s1="";
        while(j<s.size()&&s[j]!=' ') {
            s1+=s[j];
            j++;
        }
        if(v1[x]==""&&mp.find(s1)==mp.end()) {
            v1[x]=s1;
            mp[s1]=x;
        } else if(v1[x]!=""&&v1[x]!=s1) {
            return false;
        } else if(mp.find(s1)!=mp.end()&&mp[s1]!=x) {
            return false;
        }
        if(j==s.size()) {
            break;
        }
        j++;
    }
    return i==pattern.size()&&j==s.size();
}

int main() {
    string s1,s2;
    getline(cin,s2);
    cin>>s1;
    cout<<wordPattern(s1,s2)<<endl;
    return 0;
}