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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0); // Dummy node to simplify list operations
        ListNode* tail = dummy; // Pointer to track the tail of the new list
        ListNode* current = head->next; // Start with the first node after the initial zero
        
        int sum = 0;
        while (current != nullptr) {
            if (current->val == 0) {
                // Encounter a zero, so we need to create a new node with the sum
                tail->next = new ListNode(sum);
                tail = tail->next; // Move the tail
                sum = 0; // Reset the sum
            } else {
                // Accumulate the sum
                sum += current->val;
            }
            current = current->next; // Move to the next node
        }
        
        ListNode* result = dummy->next;
        delete dummy; // Clean up the dummy node
        return result;
        
    }
};
