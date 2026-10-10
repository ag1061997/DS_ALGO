#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int value) {
            this->val = value;
            this->left = nullptr;
            this->right = nullptr;
        }
};

void find(TreeNode* root, vector<vector<int> > &ans, int s, int targetSum,vector<int> t) {
    if(root==nullptr) {
        return;
    }
    t.push_back(root->val);
    s+=root->val;
    if(root->left==nullptr&&root->right==nullptr) {
        if(s==targetSum) {
            ans.push_back(t);
        }
        return;
    }
    find(root->left,ans,s,targetSum,t);
    find(root->right,ans,s,targetSum,t);
}

vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
    vector<vector<int> > ans;
    vector<int> t;
    find(root,ans,0,targetSum,t);
    return ans;
}

int main() {
    int t;
    cin>>t;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<vector<int> > ans = pathSum(root,t);
    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}