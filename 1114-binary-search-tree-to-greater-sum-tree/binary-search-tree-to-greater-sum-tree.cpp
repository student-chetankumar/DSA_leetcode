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
void inorderSolve(TreeNode* root , vector<int>&v){
    if(root==NULL){
        return;
    }
    inorderSolve(root->left,v);
    v.push_back(root->val);
    inorderSolve(root->right,v);
}

void updateTree(TreeNode* root,vector<int>&inorder,int& index){
    if(root==NULL){
        return;
    }
    updateTree(root->left,inorder,index);
    root->val = inorder[index];
    index++;
    updateTree(root->right,inorder,index);

}

    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL ){
            return NULL;
        }
        if(root->left==NULL && root->right==NULL){
            return root;
        }
        // 1.store inorder
        vector<int>inorder;
        inorderSolve(root,inorder);
        // 2.update inorder
        int n=inorder.size();
        for(int i=n-1;i>=0;i--){
            int currVal = inorder[i];
            int nextVal = 0;
            if(i+1<n){
                nextVal= inorder[i+1];
            }
            int sum  = currVal+nextVal;
            inorder[i]=sum;
        }
        // 3.update tree using inorder
        int index=0;
        updateTree(root,inorder,index);
        return root;
    }
};