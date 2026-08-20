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
ListNode* iterator(ListNode* l1, ListNode* l2) {
    ListNode* ans= new ListNode(-1);
    ListNode* it= ans;
    int c=0;
    while(l1 || l2 || c){
        int a = l1 ? l1->val : 0 ;
        int b = l2 ? l2->val : 0 ;
        int sum = a+b+c;
        int digit=sum%10;
        c=sum/10;

        // store the digit in the ans LL
        it->next = new ListNode(digit);
        it=it->next;
        l1 = l1 ? l1->next : 0;
        l2 = l2 ? l2->next : 0;

    }
    return ans->next;

}

ListNode* recursive(ListNode* l1, ListNode* l2 , int c=0) {
    // Base case
    if(!l1 && !l2 && !c){
        return NULL;
    }
    
    int a = l1 ? l1->val : 0 ;
    int b = l2 ? l2->val : 0 ;
    int sum = a+b+c;
    int digit=sum%10;
    c=sum/10;
    ListNode*ans = new ListNode(digit);
    ans->next = recursive(l1 ? l1->next : 0 , l2 ? l2->next : 0 , c);
    return ans;


}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* dummy = new ListNode(0);
        // ListNode* curr=dummy;

        // int carry=0;
        // while(l1!=NULL || l2!=NULL || carry!=0){
        //     int sum=carry;
        //     if(l1!=NULL){
        //         sum+=l1->val;
        //         l1=l1->next;
        //     }

        //     if(l2!=NULL){
        //         sum+=l2->val;
        //         l2=l2->next;
        //     }

        //     curr->next=new ListNode(sum%10);
        //     carry=sum/10;

        //     curr=curr->next;
        // }
        // return dummy->next;

        // return iterator(l1,l2);
        return recursive(l1,l2);
    }
};