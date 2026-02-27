#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    int r = matrix.size();
    int c = 0;
    if(r > 0)
        c = matrix[0].size();
    
    int top =0, bottom = r-1, right = c-1, left = 0;
    vector<int> res;
    while(top <= bottom && left <= right){
        
        for(int i=left; i <= right; ++i){
                
               res.push_back(matrix[top][i]);
                
            }
            
            for(int i=top+1; i <= bottom; ++i){
                
               res.push_back(matrix[i][right]);
                
            }
        
        
        
        
        if(top != bottom){
            
            for(int i=right-1; i > left; --i){
                
               res.push_back(matrix[bottom][i]);
                
            }
        }
        
        if(left != right){
            for(int i=bottom; i > top; --i){
                
               res.push_back(matrix[i][left]);
                
            }
            
        }
        
        top++;
        bottom--;
        left++;
        right--;
        
        
    }
    return res;
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
    vector<int> ans=spiralOrder(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}