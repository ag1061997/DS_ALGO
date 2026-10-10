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

int find(TreeNode* root, int &ans) {
    if(root==nullptr) {
        return 0;
    }
    int l=find(root->left,ans);
    int r=find(root->right,ans);
    if(root->left!=nullptr&&root->left->val==root->val) {
        l++;
    } else if (root->left != nullptr && root->left->val!=root->val) {
        l=0;
    }
    if(root->right!=nullptr&&root->right->val==root->val) {
        r++;
    } else if (root->right != nullptr && root->right->val!=root->val) {
        r=0;
    }
    if(root->left!=nullptr&&root->right!=nullptr&&root->left->val==root->val&&root->val==root->right->val) {
        ans=max(ans,l+r);
    }
    ans=max(ans,max(l,r));
    return max(l,r);
}

int longestUnivaluePath(TreeNode* root) {
    int ans=0;
    find(root,ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(5);

    cout<<longestUnivaluePath(root)<<endl;
    return 0;
}