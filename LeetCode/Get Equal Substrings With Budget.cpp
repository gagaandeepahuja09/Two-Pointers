class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLen = 0, i = 0, cost = 0;
        for(int j = 0; j < s.size(); j++) {
            cost += abs(s[j] - t[j]);
            while(cost > maxCost && i < s.size()) {
                cost -= abs(s[i] - t[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};
