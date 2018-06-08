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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* head = l1->val <= l2->val ? l1 : l2;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ListNode* prev = l1;
                l1 = l1->next;
                while (l1 && l1->val <= l2->val) {
                    prev = l1;
                    l1 = l1->next;
                }
                prev->next = l2;
            } else {
                ListNode* prev = l2;
                l2 = l2->next;
                while (l2 && l2->val < l1->val) {
                    prev = l2;
                    l2 = l2->next;
                }
                prev->next = l1;
            }
        }
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        ListNode* cur = merge(lists[0], lists[1]);
        for (int i = 2; i < lists.size(); i++)
            cur = merge(cur, lists[i]);
        return cur;
    }
};
