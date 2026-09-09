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
void solve(TreeNode* root , vector<int>&v){
    if(root==NULL)
       return;
    solve(root->left,v);
    v.push_back(root->val);
    solve(root->right,v);
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>inorder;
        solve(root,inorder);
        int ans = 0;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]>=low && inorder[i]<=high){
                ans+=inorder[i];
            }
        }
    return ans;
    }
};