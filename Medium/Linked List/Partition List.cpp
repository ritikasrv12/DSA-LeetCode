class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessHead(0); // Dummy node for nodes less than x
        ListNode greaterHead(0); // Dummy node for nodes greater than or equal to x
        ListNode* lessPtr = &lessHead;
        ListNode* greaterPtr = &greaterHead;

        while (head != nullptr) {
            if (head->val < x) {
                lessPtr->next = head;
                lessPtr = lessPtr->next;
            } else {
                greaterPtr->next = head;
                greaterPtr = greaterPtr->next;
            }
            head = head->next;
        }

        // Connect the two partitions
        lessPtr->next = greaterHead.next;
        greaterPtr->next = nullptr;

        return lessHead.next;
        
    }
};
