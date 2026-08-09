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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }

        if(n==len){
            ListNode* curr=head;
            head=head->next;
            delete curr;
            return head;
        }

        int i=1;
        ListNode* prev=head;
        while(i<len-n){
            prev=prev->next;
            i++;
        }
        ListNode* curr=prev->next;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

        return head;

    }
};