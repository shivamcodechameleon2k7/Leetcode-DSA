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

//  if you replace head1 and head2 to list1 and list2 
// then replace all the head1 and head2 to list1 and list2 in the program

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
            // IF HEAD1 == NULL 
            // RETURN HEAD2 ELSE RETURN HEAD1
        }
        // CASE 1
        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next,head2);
            return head1;
        }
        // CASE2
        else{
            head2->next = mergeTwoLists(head1,head2->next);
            return head2;
        }
    }
};