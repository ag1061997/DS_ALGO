#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int i1=0;
    int j1=0;
    for(int k=0;k<pushed.size();k++) {
        pushed[i1]=pushed[k];
        i1++;
        while(i1>0&&pushed[i1-1]==popped[j1]) {
            i1--;
            j1++;
        }
    }
    return i1==0;
}

int main() {
    int n;
    cin>>n;
    vector<int> v1(n);
    vector<int> v2(n);
    for(int i=0;i<n;i++) {
        cin>>v1[i];
    }
    for(int i=0;i<n;i++) {
        cin>>v2[i];
    }
    cout<<validateStackSequences(v1,v2)<<endl;
    return 0;
}