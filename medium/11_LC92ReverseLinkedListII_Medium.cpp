class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* forward = nullptr;
        ListNode* prevNode = nullptr;
        ListNode* sublistTail = curr;

        for (int i = 0; i <= right - left; i++) {
            forward = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = forward;
        }

        prev->next = prevNode;
        sublistTail->next = curr;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
