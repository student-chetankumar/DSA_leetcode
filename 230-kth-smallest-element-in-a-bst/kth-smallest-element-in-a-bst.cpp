/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int solve(TreeNode* root,int &i,int k){
    if(root==NULL)
     return -1;
    
    int left=solve(root->left,i,k);
    if(left != -1){
        return left;
    }
    i++;
    if(i==k){
        return root->val;
    }

    return solve(root->right,i,k);
}
void inorder(TreeNode* root, vector<int>&v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    int kthSmallest(TreeNode* root, int k) {
    //  vector<int>ans;
    //  inorder(root,ans);
    //  return ans[k-1];
    int count=0;
    return solve(root,count,k);

    }
};