#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> >& matrix) {
   int x=0;
   int y=0;
   int n=matrix.size();
   int m=matrix[0].size();
   for(int i=0;i<n;i++) {
    if(matrix[i][0]==0) {
        x=1;
        break;
    }
   } 
   for(int i=0;i<m;i++) {
    if(matrix[0][i]==0) {
        y=1;
        break;
    }
   }
   for(int i=1;i<n;i++) {
    for(int j=1;j<m;j++) {
        if(matrix[i][j]==0) {
            matrix[i][0]=0;
            matrix[0][j]=0;
        }
    }
   }
   for(int i=1;i<n;i++) {
    for(int j=1;j<m;j++) {
        if(matrix[i][0]==0||matrix[0][j]==0) {
            matrix[i][j]=0;
        }
    }
   }
   if(x) {
    for(int i=0;i<n;i++) {
        matrix[i][0]=0;
    }
   }
   if(y) {
    for(int i=0;i<m;i++) {
        matrix[0][i]=0;
    }
   }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>v[i][j];
        }
    }
    setZeroes(v);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}