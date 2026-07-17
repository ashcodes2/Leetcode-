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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head;
        int groupLen = 2;

        while (prev->next) {
            ListNode* curr = prev->next;
            int count = 0;
            ListNode* temp = curr;
            
            while (temp && count < groupLen) {
                temp = temp->next;
                count++;
            }

            if (count % 2 == 0) {
                ListNode* revPrev = temp;
                ListNode* revCurr = curr;
                for (int i = 0; i < count; ++i) {
                    ListNode* next = revCurr->next;
                    revCurr->next = revPrev;
                    revPrev = revCurr;
                    revCurr = next;
                }
                prev->next = revPrev;
                prev = curr;
            } else {
                for (int i = 0; i < count; ++i) {
                    prev = prev->next;
                }
            }
            groupLen++;
        }

        return head;
    }
};