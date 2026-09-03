/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
void solve(ListNode* head,vector<int>&ans){
    if(head==NULL){
        return;
    }
    ListNode* temp=head;
    while(temp!=NULL){
        ans.push_back(temp->val);
        temp = temp->next;
    }
}
    TreeNode* bst(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = bst(nums, left, mid - 1);
        root->right = bst(nums, mid + 1, right);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ans;
        solve(head,ans);

        return bst(ans, 0, ans.size() - 1);
    }
};