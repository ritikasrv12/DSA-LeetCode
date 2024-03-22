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
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        
        // Traverse the linked list and store values in the array
        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }
        
        // Use two pointers technique to compare elements
        int i = 0, j = values.size() - 1;
        while (i < j) {
            if (values[i] != values[j])
                return false;
            i++;
            j--;
        }
        
        return true;
        
    }
};
