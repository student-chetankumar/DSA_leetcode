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
    int getIndex(int ele, vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == ele) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int& postOrderIndex,
                    int inOrderStart, int inOrderEnd) {

        if(postOrderIndex <0 ||
           inOrderStart > inOrderEnd) {
            return NULL;
        }

        // Current element from preorder
        int element = postorder[postOrderIndex];
        postOrderIndex--;

        // Create root node
        TreeNode* root = new TreeNode(element);

        // Find root position in inorder
        int eleIndexInsideInorder = getIndex(element, inorder);


       // Build right subtree
        root->right = solve(inorder, postorder, postOrderIndex,
                            eleIndexInsideInorder + 1, inOrderEnd);

        // Build left subtree
        root->left = solve(inorder, postorder, postOrderIndex,
                           inOrderStart, eleIndexInsideInorder - 1);

     

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postOrderIndex = postorder.size()-1;
        TreeNode* root = solve(inorder,postorder,postOrderIndex,0,inorder.size()-1);
        return root;
    }
};