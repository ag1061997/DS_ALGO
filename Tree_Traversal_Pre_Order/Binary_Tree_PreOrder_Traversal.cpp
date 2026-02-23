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

void find(TreeNode* root,vector<int>& ans) {
    if(root==nullptr) {
        return;
    }
    ans.push_back(root->val);
    find(root->left,ans);
    find(root->right,ans);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    find(root,ans);
    return ans; 
}

int main() {
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    vector<int> ans=preorderTraversal(root);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}