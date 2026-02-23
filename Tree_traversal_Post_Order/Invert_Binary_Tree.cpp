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

void find(TreeNode* root) {
    if(root==nullptr) {
        return;
    }
    cout<<root->val<<" ";
    find(root->left);
    find(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    if(root==nullptr) {
        return root;
    }
    invertTree(root->left);
    invertTree(root->right);
    TreeNode* t=root->left;
    root->left=root->right;
    root->right=t;
    return root;
}

int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    find(root);
    cout<<endl;
    TreeNode* ans=invertTree(root);
    find(ans);
    cout<<endl;
    return 0;
}