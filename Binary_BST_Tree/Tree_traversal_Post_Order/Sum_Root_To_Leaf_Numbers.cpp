#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) {
            this->val=val;
            this->left=nullptr;
            this->right=nullptr;
        }
};

void find(TreeNode* root, string s, int &ans) {
    if(root==nullptr) {
        return;
    }
    if(root->left==nullptr&&root->right==nullptr) {
        ans=ans+stoi(s+to_string(root->val));
        return;
    }
    find(root->left,s+to_string(root->val),ans);
    find(root->right,s+to_string(root->val),ans);
}

int sumNumbers(TreeNode* root) {
    if(root==nullptr) {
        return 0;
    }
    int ans=0;
    find(root,"",ans);
    return ans;
}

int main() {
    TreeNode* r=new TreeNode(1);
    r->left=new TreeNode(2);
    r->right=new TreeNode(3);
    cout<<sumNumbers(r)<<endl;
}