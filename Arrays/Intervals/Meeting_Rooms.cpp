#include <bits/stdc++.h>
using namespace std;

bool canAttendMeetings(vector<vector<int> >& intervals) {
    sort(intervals.begin(),intervals.end());
    for(int i=1;i<intervals.size();i++) {
        if(intervals[i][0]<intervals[i-1][1]) {
            return false;
        }
    } 
    return true;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin>>v[i][0]>>v[i][1];
    }
    cout<<canAttendMeetings(v)<<endl;
    return 0; 
}