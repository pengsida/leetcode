class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty())
            return ans;
        int w_len = words[0].length();
        int s_len = s.length();
        unordered_map<string, int> rec;
        int target = words.size();
        for (auto& word : words)
            rec[word]++;
        vector<int> rec_num;
        for (auto it = rec.begin(); it != rec.end(); it++)
            rec_num.push_back(it->second);
        int left = 0;
        int right = 0;
        for (int i = 0; i < w_len; i++) {
            left = i;
            right = i;
            while (right <= s_len - w_len) {
                auto it = rec.find(s.substr(right, w_len));
                if (it == rec.end()) {
                    while (left != right) {
                        rec.find(s.substr(left, w_len))->second++;
                        target++;
                        left += w_len;
                    }
                    right += w_len;
                    left = right;
                    continue;
                }
                if (it->second == 0) {
                    rec.find(s.substr(left, w_len))->second++;
                    target++;
                    left += w_len;
                    continue;
                }
                it->second--;
                target--;
                if (target == 0)
                    ans.push_back(left);
                right += w_len;
            }
            int k = 0;
            for (auto it = rec.begin(); it != rec.end(); it++)
                it->second = rec_num[k++];
            target = words.size();
        } 
        return ans;
    }
};

class Solution2 {
private:
    struct Node {
        Node* child[256] = {0};
        int num = 0;
        int rec = 0;
        Node*& get(char c) {
            return child[c];
        }
    };

private:
    Node* root;
    vector<bool> visit;
    vector<int> ans;
    vector<Node*> leafs;
    
    void insert(Node* cur, string& word, int pos, int od) {
        if (pos == word.length()) {
            cur->num++;
            cur->rec = cur->num;
            leafs.push_back(cur);
            return;
        }
        auto w = word[pos];
        auto& it = cur->get(w);
        if (it == NULL)
            it = new Node();
        insert(it, word, pos + 1, od);
    }

    void find(Node* cur, string& s, int pos, int left, int t_len) {
        if (cur->num != 0) {
            if (cur->rec == 0)
                return;
            if (left == 1) {
                ans.push_back(pos - t_len);
                return;
            }
            cur->rec--;
            find(root, s, pos, left - 1, t_len);
        }
        auto w = s[pos];
        auto it = cur->get(w);
        if (it == NULL)
            return;
        find(it, s, pos + 1, left, t_len);
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        root = new Node();
        int w_len = words.size();
        visit = vector<bool>(w_len, false);
        int t_len = 0;
        for (int i = 0; i < w_len; i++) {
            insert(root, words[i], 0, i);
            t_len += words[i].length();
        }
        int s_len = s.length();
        for (int i = 0; i < s_len; i++) {
            find(root, s, i, w_len, t_len);
            for (auto leaf : leafs)
                leaf->rec = leaf->num;
        }
        return ans;
    }
};
