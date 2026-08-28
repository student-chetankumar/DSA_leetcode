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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int& preOrderIndex,
                    int inOrderStart, int inOrderEnd) {

        if(preOrderIndex >= preorder.size() ||
           inOrderStart > inOrderEnd) {
            return NULL;
        }

        // Current element from preorder
        int element = preorder[preOrderIndex];
        preOrderIndex++;

        // Create root node
        TreeNode* root = new TreeNode(element);

        // Find root position in inorder
        int eleIndexInsideInorder = getIndex(element, inorder);

        // Build left subtree
        root->left = solve(preorder, inorder, preOrderIndex,
                           inOrderStart, eleIndexInsideInorder - 1);

        // Build right subtree
        root->right = solve(preorder, inorder, preOrderIndex,
                            eleIndexInsideInorder + 1, inOrderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preOrderIndex = 0;

        return solve(preorder, inorder, preOrderIndex,
                     0, inorder.size() - 1);
    }
};