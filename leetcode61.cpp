class Solution {
public:
    void rotate(vector<ListNode*>& rec, int left, int right) {
        while (left < right) {
            int tmp = rec[left]->val;
            rec[left]->val = rec[right]->val;
            rec[right]->val = tmp;
            left++;
            right--;
        }
    }

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cur = head;
        vector<ListNode*> rec;
        while (cur != NULL) {
            rec.push_back(cur);
            cur = cur->next;
        }
        if (rec.empty())
            return head;
        k = k % rec.size();
        k = rec.size() - k - 1;
        rotate(rec, 0, k);
        rotate(rec, k + 1, rec.size() - 1);
        rotate(rec, 0, rec.size() - 1);
        return head;
    }
};
