#include <bits/stdc++.h>
using namespace std;

void find(int start, int end, vector<string> &ans, string s) {
    if(start==0&&end==0) {
        ans.push_back(s);
        return;
    }
    if(start<0||end<0||end<start) {
        return;
    }
    find(start-1,end,ans,s+'(');
    find(start,end-1,ans,s+')');
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    find(n,n,ans,"");
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<string> ans=generateParenthesis(n);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
}