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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = head;
        ListNode* prev = &dummy;
        for(int i = 1; i < left;i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode* leftNode = curr;
        ListNode* rev = nullptr;
        for(int i = 0; i < right-left+1;i++){
            ListNode* next;
            next = curr->next;
            curr->next = rev;
            rev = curr;
            curr = next; 
        }
        prev->next = rev;
        leftNode->next = curr;
        return dummy.next;
    }
    
};