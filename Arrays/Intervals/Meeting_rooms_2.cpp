#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    int ans=0;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<intervals.size();i++) {
        while(!pq.empty()&&pq.top()<=intervals[i][0]) {
            pq.pop();
        }
        pq.push(intervals[i][1]);
        ans=max(ans,(int)pq.size());
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
    cout<<minMeetingRooms(v)<<endl;
}