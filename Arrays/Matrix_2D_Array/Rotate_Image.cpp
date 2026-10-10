#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> >& matrix) {
    int n=matrix.size();
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n/2;j++) {
            swap(matrix[i][j],matrix[i][n-j-1]);
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>v[i][j];
        }
    }
    rotate(v);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}