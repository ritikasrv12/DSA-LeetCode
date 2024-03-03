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
         ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move the first pointer ahead by n+1 steps
        for (int i = 0; i < n + 1; i++) {
            first = first->next;
        }
        
        // Move both pointers until the first pointer reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Remove the nth node from the end
        second->next = second->next->next;
        
        // Store the actual head
        ListNode* result = dummy->next;
        delete dummy; // Free dummy node memory
        
        return result;
        
    }
};
