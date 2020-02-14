class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxIdx = s[0] - 'A', maxFreq = 1;
        vector<int> cnt(26, 0);
        int j = 0, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'A';
            maxFreq = max(maxFreq, ++cnt[idx]);
            if(maxFreq == cnt[idx]) {
                maxIdx = idx;
            }
            while(j < s.size() && (i - j + 1 - maxFreq) > k) {
                cnt[s[j++] - 'A']--;
                maxIdx = -1, maxFreq = 0;
                for(int c = 0; c < 26; c++) {
                    if(maxIdx == -1 || cnt[c] > cnt[maxIdx]) {
                        maxIdx = c;
                        maxFreq = cnt[c];
                    }
                }
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
