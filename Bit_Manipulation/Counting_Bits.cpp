#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans;
    ans.push_back(0);
    if(n>=1) {
        ans.push_back(1);
    }
    int x=1;
    int y=1;
    while(ans.size()<n+1) {
        if(x==y) {
            ans.push_back(1);
            x=x+y;
            y=1;
        } else {
            ans.push_back(1+ans[y]);
            y++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> ans = countBits(n);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}