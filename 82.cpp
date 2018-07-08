class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode(-1);
        ListNode* node = head;
        ListNode* tail = res;
        int count = 1;
        while (node != nullptr) {
            if (node->next) {
                if (node->val == node->next->val) {
                    ++count;
                } else {
                    if (count == 1) {
                        tail->next = node;
                        tail = tail->next;
                    } else {
                        count = 1;
                    }
                }
            } else {
                if (count == 1) {
                    tail->next = node;
                    tail = tail->next;
                }
            }
            node = node->next;
        }
        tail->next = nullptr;
        return res->next;
    }
};