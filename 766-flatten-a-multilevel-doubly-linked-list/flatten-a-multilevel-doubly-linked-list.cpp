/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node* curr = head;
        while(curr != nullptr){
        // valid child
            if(curr->child != nullptr){
                Node* next = curr->next;
                Node* child = curr->child;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;
                while(curr->next != nullptr){
                     curr = curr->next;
                }
                if(next != nullptr){
                    curr->next = next;
                    next->prev = curr;
                }
            }
            // if (curr->next == nullptr) {
            //     return curr;
            // }
            curr = curr->next;
        }
        return head; 
    }  
};