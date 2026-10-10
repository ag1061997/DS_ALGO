#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char> >& board, vector<vector<int> > &dir, string &word,int m,int n,int x,int y,int k,int idx,bool &ans) {
        if(ans||(idx==k-1)) {
            ans=true;
            return;
        }
        for(int i=0;i<4;i++) {
            int x1=x+dir[i][0];
            int y1=y+dir[i][1];
            if(x1>=0&&x1<m&&y1>=0&&y1<n&&board[x1][y1]!='#'&&word[idx+1]==board[x1][y1]) {
                char temp=board[x1][y1];
                board[x1][y1]='#';
                dfs(board,dir,word,m,n,x1,y1,k,idx+1,ans);
                board[x1][y1]=temp;
            }
        }
}

bool exist(vector<vector<char> >& board, string word) {
    bool ans=false;
    int m=board.size();
    int n=board[0].size();
    int k=word.size();
    vector<vector<int> > dir(4,vector<int>(2,0));
    dir[0][0]=1;
    dir[1][0]=-1;
    dir[2][1]=1;
    dir[3][1]=-1;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(word[0]==board[i][j]) {
                char temp=board[i][j];
                board[i][j]='#';
                dfs(board,dir,word,m,n,i,j,k,0,ans);
                board[i][j]=temp;
                if(ans==true) {
                    return ans;
                }
            }
        }
    }
    return false;
}

int main() {
    int m,n;
    string s;
    cin>>m>>n>>s;
    vector<vector<char> > v(m,vector<char>(n));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>v[i][j];
        }
    }
    cout<<exist(v,s)<<endl;
}