class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* answer = head -> next;
        ListNode* curr = head;

        head = head -> next -> next;
        answer -> next = curr;

        while(head) {
            auto f = head, s = head -> next;
            if(!s) {
                curr -> next = head;
                return answer;
            }

            head = head -> next -> next;

            curr -> next = s;
            curr = s;
            curr -> next = f;
            curr = f;
        }
        curr -> next = nullptr;
        return answer;
        
    }
};
