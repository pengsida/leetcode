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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = cur->next;
        if (next == NULL)
            return cur;
        ListNode* ans = next;
        while (next) {
            if (prev)
                prev->next = next;
            cur->next = next->next;
            next->next = cur;
            prev = cur;
            cur = cur->next;
            if (!cur)
                return ans;
            next = cur->next;
        }
        return ans;
    }
};

class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode** cur = &head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        while ((a = *cur) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *cur = b;
            cur = &(a->next);
        }
        return head;
    }
};
