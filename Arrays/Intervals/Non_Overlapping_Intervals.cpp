#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int> >& intervals) {
    int ans=0;
    sort(intervals.begin(),intervals.end());
    int y=intervals[0][1];
    
    for(int i=1;i<intervals.size();i++) {
        if(intervals[i][0]>=y) {
            y=intervals[i][1];
        } else {
            ans++;
            y=min(y,intervals[i][1]);
        }
    }

    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin>>v[i][0]>>v[i][1];
    }

    cout<<eraseOverlapIntervals(v)<<endl;

    return 0;
}