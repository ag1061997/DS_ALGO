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

int find(TreeNode* root,int &ans) {
    if(root==nullptr) {
        return 0;
    }
    int l=find(root->left,ans);
    int r=find(root->right,ans);
    ans=max(ans,l+r);
    return max(l,r)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans=0;
    find(root,ans);
    return ans;
}

int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    cout<<diameterOfBinaryTree(root)<<endl;
    return 0;
}