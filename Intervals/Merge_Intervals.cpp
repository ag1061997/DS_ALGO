#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > merge(vector<vector<int> >& intervals) {
    vector<vector<int> > ans;
    sort(intervals.begin(),intervals.end());
    int x=intervals[0][0];
    int y=intervals[0][1];
    
    for(int i=1;i<intervals.size();i++) {
        if(intervals[i][0]>y) {
            vector<int> t;
            t.push_back(x);
            t.push_back(y);
            ans.push_back(t);
            x=intervals[i][0];
            y=intervals[i][1];
        } else {
            y=max(y,intervals[i][1]);
        }
    }
    vector<int> t;
    t.push_back(x);
    t.push_back(y);
    ans.push_back(t);

    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin>>v[i][0]>>v[i][1];
    }

    vector<vector<int> > ans=merge(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}