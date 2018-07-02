class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr || m == n)
            return head;
        ListNode* frtHead = new ListNode(-1);
        frtHead->next = head;
        ListNode* frtTail = frtHead;
        for (int i = 0; i < m - 1; ++i)
            frtTail = frtTail->next;
        ListNode* curNode = frtTail->next;
        ListNode* nxtNode = curNode->next;
        for (int i = m; i < n; ++i) {
            ListNode* nxtNxtNode = nxtNode->next;
            nxtNode->next = curNode;
            curNode = nxtNode;
            nxtNode = nxtNxtNode;
        }
        frtTail->next->next = nxtNode;
        frtTail->next = curNode;
        return frtHead->next;
    }
};