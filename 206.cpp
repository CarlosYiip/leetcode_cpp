class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* currNode = head;
        ListNode* nextNode = head->next;
        while (currNode && nextNode ) {
            ListNode* nextNextNode = nextNode->next;
            nextNode->next = currNode;
            currNode = nextNode;
            nextNode = nextNextNode;
        }
        
        head->next = nullptr;
        return currNode;
    }
};