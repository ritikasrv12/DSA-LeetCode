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
    ListNode* doubleIt(ListNode* head) {
        int num = 0;
        ListNode* current = head;
        while (current) {
            num = num * 10 + current->val;
            current = current->next;
        }
        
        // Step 2: Double the integer obtained
        num *= 2;
        
        // Step 3: Convert the doubled integer back into a linked list representation
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        if (num == 0) {
            return new ListNode(0); // Handling case when num is 0
        }
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            tail->next = new ListNode(digit);
            tail = tail->next;
        }
        
        // Reverse the list (optional)
        ListNode* reversed = reverseList(dummy->next);
        return reversed;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
        
    }
};
