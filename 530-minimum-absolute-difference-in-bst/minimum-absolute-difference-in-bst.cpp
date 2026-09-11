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
    if(root==NULL){
        return;
    }
    solve(root->left,v);
    v.push_back(root->val);
    solve(root->right,v);

}
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        int mini=INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            int diff = abs(ans[i]-ans[i+1]);
            mini = min(mini,diff);
        }
        return mini;
    }
};