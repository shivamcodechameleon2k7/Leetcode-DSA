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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *current = &dummy;
        int carry = 0;
        int val1;
        int val2;
        while(l1 != NULL || l2 != NULL || carry !=0){
            if(l1 != NULL){
                val1 = l1->val; 
            }
            else{
                val1 = 0;
            }
            if(l2 != NULL){
                val2 = l2->val;
            }
            else{
                val2 = 0;
            }
            int sum = val1 + val2 + carry;
            int val = sum % 10;
            carry = sum / 10;
            if( l1 != NULL){
                l1 = l1->next;
            }
            if( l2 != NULL){
                l2 =l2->next;
            }
            current->next = new ListNode(val);
            current = current->next;
        }
        return dummy.next;   
    }   
};