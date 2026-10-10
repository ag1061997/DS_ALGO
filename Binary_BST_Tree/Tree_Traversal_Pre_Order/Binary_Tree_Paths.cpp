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

void find(TreeNode* root,vector<string> &ans,string s) {
    if(root==nullptr) {
        return;
    }
    if(s!="") {
        s+="->";
    }
    s+=to_string(root->val);
    if(root->left==nullptr&&root->right==nullptr) {
        ans.push_back(s);
        return;
    }
    find(root->left,ans,s);
    find(root->right,ans,s);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    if(root==nullptr) {
        return ans;
    }
    find(root,ans,"");
    return ans;
}

int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(5);

    vector<string> ans=binaryTreePaths(root);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}