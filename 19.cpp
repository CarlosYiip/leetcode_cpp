class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* virHead = new ListNode(-1);
        virHead->next = head;
        ListNode* fast = virHead;
        ListNode* slow = virHead;
        for (int i = 0; i < n + 1; ++i) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return virHead->next;
    }
};