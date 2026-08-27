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
bool solve(TreeNode* root,int targetSum,int sum){
    if(root==NULL) return false;

    sum = sum+root->val;

    if(root->left==NULL && root->right==NULL ){
        if(sum==targetSum){
            return true;
        }else{
            return false;
        }
    }

    bool lAns = solve(root->left,targetSum,sum);
    bool rAns = solve(root->right,targetSum,sum);
    return lAns || rAns;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
   
    // if(!root) return false;
    // targetSum=targetSum-root->val;
    // if(root->left == NULL && root->right==NULL && targetSum==0){
    //    return true;
    // }
    // return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
     
     int sum =0 ;
     bool ans = solve(root,targetSum,sum);
     return ans;
    }
};