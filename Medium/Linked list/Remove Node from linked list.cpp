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
ListNode* reverseList(ListNode*head){
    ListNode *p = head, *q=head->next, *r;
     if(q == nullptr) return p;
     p->next = nullptr;
     while(q != nullptr){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
     }
     return p;

}
    ListNode* removeNodes(ListNode* head) {
       if(head == nullptr) return head;
       ListNode* newHead = reverseList(head);

       int maxSoFar = newHead->val;
       ListNode *p = newHead, *q = newHead->next, *r;
       while(q != nullptr){
            r = q->next;
            if(q->val < maxSoFar){
                p->next = r;
                q = r;
            }else{
                maxSoFar = q->val;
                p = q;
                q = r;
            }
            
        }

        newHead = reverseList(newHead);
        return newHead;
    }
};
