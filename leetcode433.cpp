class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty())
            return 0;
        int count = 1;
        int cur = 0;
        char prev = chars[0];
        int size = chars.size();
        for (int i = 1; i < size; i++) {
            auto w = chars[i];
            if (prev == w) {
                count++;
                continue;
            }
            chars[cur++] = prev;
            if (count != 1) {
                string tmp = to_string(count);
                for (auto t : tmp)
                    chars[cur++] = t;
            }
            prev = w;
            count = 1;
        }
        chars[cur++] = prev;
        if (count != 1) {
            string tmp = to_string(count);
            for (auto t : tmp)
                chars[cur++] = t;
        }
        return cur;
    }
};
