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

void find(TreeNode* root,int &k,int &ans) {
    if(root==nullptr||ans!=INT_MIN) {
        return;
    }
    find(root->left,k,ans);
    k--;
    if(k==0) {
        ans=root->val;
        return;
    }
    find(root->right,k,ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans=INT_MIN;
    find(root,k,ans);
    return ans;   
}

int main() {
    int k;
    cin>>k;

    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(1);
    root->right=new TreeNode(4);
    root->left->right=new TreeNode(2);

    cout<<kthSmallest(root,k)<<endl;
    return 0;
}