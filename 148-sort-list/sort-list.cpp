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

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (left != nullptr && right != nullptr) {

            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        // Remaining nodes
        if (left != nullptr) {
            temp->next = left;
        }
        else {
            temp->next = right;
        }

        return dummy->next;
    }


    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break into two lists
        prev->next = nullptr;

        // Sort left and right
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge
        return merge(left, right);
    }
};
        