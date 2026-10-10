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

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > ans;
    if(root==nullptr) {
        return ans;
    }
    queue<vector<TreeNode*> > q;
    vector<TreeNode*> t;
    vector<int> t2;
    t.push_back(root);
    q.push(t);
    while(!q.empty()) {
        t2.clear();
        t.clear();
        vector<TreeNode*> p=q.front();
        q.pop();
        for(int i=0;i<p.size();i++) {
            t2.push_back(p[i]->val);
            if(p[i]->left) {
                t.push_back(p[i]->left);
            }
            if(p[i]->right) {
                t.push_back(p[i]->right);
            }
        }
        ans.push_back(t2);
        if(t.size()>0) {
            q.push(t);
        }
    }
    return ans;  
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    vector<vector<int> > ans=levelOrder(root);
    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}