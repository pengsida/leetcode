#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> rec;
        while (head) {
            rec.push_back(head);
            head = head->next;
        }
        int size = rec.size();
        return rec[size / 2];
    }
};
