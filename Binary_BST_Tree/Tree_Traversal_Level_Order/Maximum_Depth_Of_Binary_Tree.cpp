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

int maxDepth(TreeNode* root) {
    if(root==nullptr) {
        return 0;
    }
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return max(l,r)+1;
}

int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    cout<<maxDepth(root)<<endl;
    return 0;
}