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

int maxDepth(TreeNode* root,bool &ans) {
    if(root==nullptr) {
        return 0;
    }
    int l=maxDepth(root->left,ans);
    int r=maxDepth(root->right,ans);
    if(abs(l-r)>1) {
        ans=false;
    }
    return max(l,r)+1;
}

bool isBalanced(TreeNode* root) {
    bool ans=true;
    maxDepth(root,ans);
    return ans;
}

int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    cout<<isBalanced(root)<<endl;
    return 0;
}