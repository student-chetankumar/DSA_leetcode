class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& v) {
        if(root == NULL) {
            return;
        }

        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> ans;

        inorder(root, ans);

        TreeNode* first = NULL;
        TreeNode* second = NULL;

        for(int i = 0; i < ans.size() - 1; i++) {

            if(ans[i]->val > ans[i+1]->val) {

                if(first == NULL) {
                    first = ans[i];
                }

                second = ans[i+1];
            }
        }

        swap(first->val, second->val);
    }
};