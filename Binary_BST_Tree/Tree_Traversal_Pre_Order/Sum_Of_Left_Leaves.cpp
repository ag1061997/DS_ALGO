#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) {
            this->val=x;
            this->left=nullptr;
            this->right=nullptr;
        }
};

void find(TreeNode* root,int &ans,int h) {
    if(root==nullptr) {
        return;
    }
    if(root->left==nullptr&&root->right==nullptr) {
        if(h==-1) {
            ans+=root->val;
        }
        return;
    }
    find(root->left,ans,-1);
    find(root->right,ans,1);
    return;
}

int sumOfLeftLeaves(TreeNode* root) {
    int ans=0;
    find(root,ans,0);
    return ans;
}

int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    cout<<sumOfLeftLeaves(root)<<endl;
    return 0;
}