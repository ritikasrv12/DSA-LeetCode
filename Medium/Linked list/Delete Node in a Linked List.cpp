/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;  // Get the next node
        node->val = nextNode->val;        // Copy the value of the next node
        node->next = nextNode->next;      // Update the next pointer of the current node
        delete nextNode; 
        
    }
};
