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

void find(TreeNode* root,long &s,bool &ans) {
    if(root==nullptr||ans==false) {
        return;
    }
    find(root->left,s,ans);
    if(root->val<=s) {
        ans=false;
        return;
    }
    s=root->val;
    find(root->right,s,ans);
}

bool isValidBST(TreeNode* root) {
    long s=LONG_MIN;
    bool ans=true;
    find(root,s,ans);
    return ans; 
}

int main() {
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);

    cout<<isValidBST(root)<<endl;
    return 0;
}