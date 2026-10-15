#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
    vector<vector<int> > ans;
    for(int i=0;i<intervals.size();i++) {
        if(intervals[i][1]<newInterval[0]) {
            ans.push_back(intervals[i]);
        } else {
            if(intervals[i][0]>newInterval[1]) {
                ans.push_back(newInterval);
            } else {
                int x=min(intervals[i][0],newInterval[0]);
                int y=max(intervals[i][1],newInterval[1]);
                i++;
                while(i<intervals.size()&&y>=intervals[i][0]) {
                    y=max(intervals[i][1],newInterval[1]);
                    i++;
                }
                ans.push_back({x,y});
            }
            while(i<intervals.size()) {
                ans.push_back(intervals[i]);
                i++;
            }
            return ans;
        }
    }
    ans.push_back(newInterval);
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(2));
    vector<int> v2(2);
    for(int i=0;i<n;i++) {
        cin>>v[i][0]>>v[i][1];
    }
    cin>>v2[0]>>v2[1];
    vector<vector<int> > ans=insert(v,v2);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
}