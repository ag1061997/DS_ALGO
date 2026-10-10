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

int widthOfBinaryTree(TreeNode* root) {
    int ans=0;
    if(root==nullptr) {
        return ans;
    }
    queue<vector<pair<TreeNode*,long long> > > q;
    vector<pair<TreeNode*,long long> > t;
    ans=1;
    t.push_back(make_pair(root,0));
    q.push(t);
    while(!q.empty()) {
        t.clear();
        vector<pair<TreeNode*,long long > > p=q.front();
        q.pop();
        for(int i=0;i<p.size();i++) {
            if(p[i].first->left!=nullptr) {
                t.push_back(make_pair(p[i].first->left,(p[i].second-p[0].second)*2+1));
            }
            if(p[i].first->right!=nullptr) {
                t.push_back(make_pair(p[i].first->right,(p[i].second-p[0].second)*2+2));
            }
        }
        if(t.size()>0) {
            int x=(int)(t[t.size()-1].second-t[0].second+1);
            ans=max(ans,x);
            q.push(t);
        }
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<widthOfBinaryTree(root)<<endl;
    return 0;
}