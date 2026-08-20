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
    ListNode* partition(ListNode* head, int x) {
        ListNode*fp= new ListNode(-1);
        ListNode*sp= new ListNode(-1);

        auto fpTail = fp;
        auto spTail = sp;
        auto it = head;
        while(it){
            if(it->val < x){
                fpTail->next = it;
                fpTail = fpTail->next;
            }else{
                spTail->next = it;
                spTail = spTail->next;
            }
            it=it->next;
        }
        // fp->sp->null
        fpTail->next = sp->next;
        spTail->next = 0;
        return fp->next;
    }
};