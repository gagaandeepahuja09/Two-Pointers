class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        for(int h= 1; h <= 26; h++) {
            int i = 0, j = 0, unique = 0, noLessk = 0;
            vector<int> cnt(26, 0);
            while(j < s.size()) {
                if(unique <= h) {
                    int c = s[j] - 'a';
                    if(cnt[c]++ == 0)
                        unique++;
                    if(cnt[c] == k)
                        noLessk++;
                    j++;
                }
                else {
                    int c = s[i] - 'a';
                    if(cnt[c]-- == k)
                        noLessk--;
                    if(cnt[c] == 0)
                        unique--;
                    i++;
                }
                if(noLessk == unique) {
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }
};
