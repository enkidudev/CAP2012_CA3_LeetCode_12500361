class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            ++length;
        }

        k = k % length;
        if (k == 0) return head;

        tail->next = head;

        int stepsToNewTail = length - k;
        ListNode* newTail = tail;
        for (int i = 0; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
