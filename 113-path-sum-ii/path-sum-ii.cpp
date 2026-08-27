class Solution {
public:
    void solve(TreeNode* root, int targetSum, int currSum,
               vector<int>& path, vector<vector<int>>& ans) {
        
        if (root == NULL) return;

        // include current node
        path.push_back(root->val);
        currSum += root->val;

        // leaf node check
        if (root->left == NULL && root->right == NULL) {
            if (currSum == targetSum) {
                ans.push_back(path);
            }
        }

        // recursive calls
        solve(root->left, targetSum, currSum, path, ans);
        solve(root->right, targetSum, currSum, path, ans);

        // BACKTRACK
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int currSum=0;
        vector<int> path;
        solve(root, targetSum, currSum, path, ans);
        return ans;
    }
};
