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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr&&q==nullptr) {
        return true;
    } else if(p==nullptr||q==nullptr||p->val!=q->val) {
        return false;
    }
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}

int main() {
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);

    TreeNode* root2=new TreeNode(1);
    root2->right=new TreeNode(2);
    root2->right->left=new TreeNode(3);

    cout<<isSameTree(root,root2)<<endl;
    return 0;
}