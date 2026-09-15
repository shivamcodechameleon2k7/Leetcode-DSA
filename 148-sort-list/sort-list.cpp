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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
         ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* p1 = left;
        ListNode* p2 = right;
        while(p1 != nullptr && p2 != nullptr){
            if(p1->val <= p2->val){
                temp->next = p1;
                p1 = p1->next;
            }
            else{
                temp->next = p2;
                p2 = p2->next;
            }
            temp = temp->next;
        }
        if(p1 != nullptr){
            temp->next = p1;
        }
        else{
            temp->next = p2;
        }
        return dummy->next;
    }
};