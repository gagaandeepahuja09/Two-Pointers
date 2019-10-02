class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int ret = 0, i = 0, j = 0;
        while(j < s.size()) {
            if((k -= abs(s[j] - t[j++])) < 0)
                k += abs(s[i] - t[i++]);
            ret = max(ret, j - i);
        }
        return ret;
    }
};
