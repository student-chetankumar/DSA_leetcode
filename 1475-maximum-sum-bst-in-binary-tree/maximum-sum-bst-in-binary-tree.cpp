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
class Info {
public:
    int minval;
    int maxval;
    int sum;
    int isBST;
};

class Solution {
public:

    Info solve(TreeNode* root, int &sum) {

        if (root == NULL) {
            Info temp;
            temp.minval = INT_MAX;
            temp.maxval = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;

            return temp;
        }

        // LRN -> Left, Right, Node
        Info leftAns = solve(root->left, sum);
        Info rightAns = solve(root->right, sum);

        // Current node
        Info currentAns;

        currentAns.minval =
            min(root->val,
                min(leftAns.minval, rightAns.minval));

        currentAns.maxval =
            max(root->val,
                max(leftAns.maxval, rightAns.maxval));

        currentAns.sum =
            root->val + leftAns.sum + rightAns.sum;

        currentAns.isBST = false;

        // Check whether current subtree is BST
        if (root->val > leftAns.maxval &&
            root->val < rightAns.minval &&
            leftAns.isBST &&
            rightAns.isBST) {

            currentAns.isBST = true;

            sum = max(sum, currentAns.sum);
        }

        return currentAns;
    }

    int maxSumBST(TreeNode* root) {

        int sum = 0;

        solve(root, sum);

        return sum;
    }
};