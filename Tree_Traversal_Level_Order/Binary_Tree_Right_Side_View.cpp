#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) {
            val=x;
            left=nullptr;
            right=nullptr;
        }
};

void find(TreeNode* root,vector<int> &ans,int h) {
    if(root==nullptr) {
        return;
    }
    if(h==ans.size()) {
        ans.push_back(root->val);
    }
    find(root->right,ans,h+1);
    find(root->left,ans,h+1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    find(root,ans,0);
    return ans;    
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    vector<int> ans=rightSideView(root);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}