#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();
    int l1=0;
    int r1=n-1;
    while(l1<=r1) {
        int m1=l1+(r1-l1)/2;
        if(target>=matrix[m1][0]&&target<=matrix[m1][m-1]) {
            int l2=0;
            int r2=m-1;
            while(l2<=r2) {
                int m2=l2+(r2-l2)/2;
                if(matrix[m1][m2]==target) {
                    return true;
                } else if(matrix[m1][m2]<target) {
                    l2=m2+1;
                } else {
                    r2=m2-1;
                }
            }
            return false;
        } else if(target<matrix[m1][0]) {
            r1=m1-1;
        } else {
            l1=m1+1;
        }
    }
    return false;
}

int main() {
    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<int> > v(m,vector<int>(n));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>v[i][j];
        }
    }
    cout<<searchMatrix(v,k)<<endl;
}