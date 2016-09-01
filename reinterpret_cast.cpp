class Solution {
    uintptr_t acc = 0;  //an unsigned int that is capable of storing a pointer.

    ListNode* reverse(ListNode *head) {
        ListNode *prev = nullptr, *tmp;
        while (head) {
            acc ^= reinterpret_cast<uintptr_t> (head);
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        p = reverse(p);
        q = reverse(q);
        p = reverse(p);
        if (q != headA) q = reverse(q);
        return reinterpret_cast<ListNode*> (acc);
    }
};
