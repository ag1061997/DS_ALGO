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

bool find(TreeNode* p, TreeNode* q) {
    if(p==nullptr&&q==nullptr) {
        return true;
    } else if(p==nullptr||q==nullptr||p->val!=q->val) {
        return false;
    }
    return find(p->left,q->right)&&find(p->right,q->left);
}

bool isSymmetric(TreeNode* root) {
    if(root==nullptr) {
        return true;
    }   
    return find(root->left,root->right);
}

int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->right=new TreeNode(2);
    root->right->right=new TreeNode(3);

    cout<<isSymmetric(root)<<endl;
    return 0;
}