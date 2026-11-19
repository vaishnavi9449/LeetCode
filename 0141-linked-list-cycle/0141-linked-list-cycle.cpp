class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;        // Move one step
            fast = fast->next->next;  // Move two steps
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
