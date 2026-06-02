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

pair<TreeNode*,bool> find(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr) {
        return make_pair(nullptr,false); 
    }
    pair<TreeNode*,bool> l=find(root->left,p,q);
    if(l.first!=nullptr) {
        return l;
    }
    pair<TreeNode*,bool> r=find(root->right,p,q);
    if(r.first!=nullptr) {
        return r;
    }
    if(l.second==true&&r.second==true) {
        return make_pair(root,false);
    }
    if(((l.second==true||r.second==true)&&(root->val==p->val || root->val==q->val))) {
        return make_pair(root,false);
    }
    if(root->val==p->val || root->val==q->val) {
        return make_pair(nullptr,true);
    }
    return l.second==true?l:r;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    pair<TreeNode*,bool> ans=find(root,p,q);
    return ans.first;
}

int main() {
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(5);
    root->right=new TreeNode(1);
    TreeNode* p=root->left;
    TreeNode* q=root->right;
    TreeNode* ans=lowestCommonAncestor(root,p,q);
    if(ans!=nullptr) {
        cout<<ans->val<<endl;
    } else {
        cout<<INT_MIN<<endl;
    }
    return 0;
}