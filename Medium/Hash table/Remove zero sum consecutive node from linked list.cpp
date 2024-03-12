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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Dummy node to handle the case where the whole list sums to zero
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        unordered_map<int, ListNode*> prefixSumMap;
        int prefixSum = 0;
        ListNode* curr = dummy;
        
        while (curr) {
            prefixSum += curr->val;
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                // Remove nodes between the two same prefix sum nodes
                ListNode* prev = prefixSumMap[prefixSum]->next;
                int sum = prefixSum + prev->val;
                while (prev != curr) {
                    sum += prev->val;
                    prefixSumMap.erase(sum);
                    prev = prev->next;
                }
                prefixSumMap[prefixSum]->next = curr->next;
            } else {
                prefixSumMap[prefixSum] = curr;
            }
            curr = curr->next;
        }
        
        return dummy->next;
        
    }
};
