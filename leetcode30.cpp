class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int n = S.size(), cnt = L.size();
        if (n <= 0 || cnt <= 0) return ans;

        // init word occurence
        unordered_map<string, int> dict;
        for (int i = 0; i < cnt; ++i) dict[L[i]]++;

        // travel all sub string combinations
        int wl = L[0].size();
        for (int i = 0; i < wl; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> tdict;
            for (int j = i; j <= n - wl; j += wl) {
                string str = S.substr(j, wl);
                // a valid word, accumulate results
                if (dict.count(str)) {
                    tdict[str]++;
                    if (tdict[str] <= dict[str]) 
                        count++;
                    else {
                        // a more word, advance the window left side possiablly
                        while (tdict[str] > dict[str]) {
                            string str1 = S.substr(left, wl);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str1]) count--;
                            left += wl;
                        }
                    }
                    // come to a result
                    if (count == cnt) {
                        ans.push_back(left);
                        // advance one word
                        tdict[S.substr(left, wl)]--;
                        count--;
                        left += wl;
                    }
                }
                // not a valid word, reset all vars
                else {
                    tdict.clear();
                    count = 0;
                    left = j + wl;
                }
            }
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
