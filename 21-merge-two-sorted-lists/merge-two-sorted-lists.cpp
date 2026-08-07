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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy= new ListNode(-1);
        ListNode* temp= dummy;
        ListNode* p=list1;
        ListNode* q=list2;
        while(p!=NULL && q!=NULL){
            if(p->val<q->val){
                temp->next=p;
                p=p->next;
            }else{
                temp->next=q;
                q=q->next;
            }
            temp=temp->next;
        }
    if(p!=NULL){
        temp->next=p;
    }
    if(q!=NULL){
        temp->next=q;
    }

    return dummy->next;
    
    }
};