#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) {
            val=x;
            this->left=nullptr;
            this->right=nullptr;
        }
};

void find(TreeNode* root,int targetSum, unordered_map<int,int>&mp, int s,int &ans) {
    if(root==nullptr) {
        return;
    }
    int x=s+root->val;
    if(mp.find(x-targetSum)!=mp.end()) {
        ans+=mp[x-targetSum];
    }
    if(mp.find(x)==mp.end()) {
        mp[x]=1;
    } else {
        mp[x]++;
    }
    find(root->left,targetSum,mp,x,ans);
    find(root->right,targetSum,mp,x,ans);
    if(mp[x]==1) {
        mp.erase(x);
    } else {
        mp[x]--;
    }
}

int pathSum(TreeNode* root, int targetSum) {
    unordered_map<int,int> mp;
    mp[0]=1;
    int s=0;
    int ans=0;
    find(root,targetSum,mp,s,ans);
    return ans;
}

int main() {
    int t;
    cin>>t;

    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(3);

    cout<<pathSum(root,t)<<endl;
    return 0;
}