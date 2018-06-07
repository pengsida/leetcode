/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> rec;
        ListNode* cur = head;
        while (cur != NULL) {
            rec.push_back(cur);
            cur = cur->next;
        }
        int pos = rec.size() - n;
        if (pos == 0) {
            cur = head->next;
            delete head;
            head = NULL;
            return cur;
        }
        ListNode* prev = rec[pos - 1];
        prev->next = rec[pos]->next;
        delete rec[pos];
        rec[pos] = NULL;
        return head;
    }
};
