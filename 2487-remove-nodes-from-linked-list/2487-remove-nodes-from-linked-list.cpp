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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) return head;

        // Step 1: Reverse the linked list to process right-to-left
        head = reverseList(head);

        // Step 2: Keep track of the maximum value seen so far
        ListNode* curr = head;
        int maxVal = curr->val;

        while (curr && curr->next) {
            if (curr->next->val < maxVal) {
                // Skip the node since a larger value exists to its right
                curr->next = curr->next->next;
            } else {
                // Update maxVal and advance
                maxVal = curr->next->val;
                curr = curr->next;
            }
        }

        // Step 3: Reverse back to restore the original relative order
        return reverseList(head);
    }
};