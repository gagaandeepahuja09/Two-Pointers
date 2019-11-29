class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, i = 0, maxFreq = 0, maxLen = 0;
        vector<int> cnt(26, 0);
        for(int j = 0; j < s.size(); j++) {
            int len = j - i + 1;
            maxFreq = max(maxFreq, ++cnt[s[j] - 'A']);
            while((j - i + 1) - maxFreq > k) {
                cnt[s[i++] - 'A']--;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};
