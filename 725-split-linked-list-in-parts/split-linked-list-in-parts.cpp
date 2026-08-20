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
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = 0;
        auto it = head;
        // Count total nodes
        while(it){
            N++;
            it=it->next;
        }

        // determine size of each part
        int idealPartSize = N/k;
        int extraNodes = N%k;

        vector<ListNode*> ans(k,NULL);
        it=head;
        for(int i=0;i<k && it;i++){
            ans[i] = it;
            int actualPartSize = idealPartSize + (extraNodes -- > 0? 1 : 0);
            for(int j=0;j<actualPartSize-1;j++)
                it = it->next;
            
            auto nextPartStarting = it->next;
            it->next = NULL;
            it = nextPartStarting; 
        }
        return ans;
    }
};