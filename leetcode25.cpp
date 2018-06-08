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
    bool gather(vector<ListNode*>& rec, ListNode* cur, int k) {
        int i = 0;
        for (i = 0; i < k; i++) {
            if (cur == NULL)
                break;
            rec[i] = cur;
            cur = cur->next;
        }
        return i == k;
    }
    
    void reverse(vector<ListNode*>& rec, int k) {
        ListNode* tmp = rec[k - 1]->next;
        for (int i = k - 1; i >= 1; i--)
            rec[i]->next = rec[i - 1];
        rec[0]->next = tmp;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        vector<ListNode*> rec(k, NULL);
        ListNode** cur = &head;
        while (1) {
            if (!gather(rec, *cur, k))
                break;
            reverse(rec, k);
            *cur = rec.back();
            cur = &(rec.front()->next);
        }
        return head;
    }
};
