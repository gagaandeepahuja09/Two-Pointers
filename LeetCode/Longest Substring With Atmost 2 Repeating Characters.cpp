class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int> mp;
        int mx = 0, j = 0;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            while(j < s.size() && mp.size() > 2) {
                if(--mp[s[j]] == 0) {
                    mp.erase(s[j]);
                }
                j++;
            }
            mx = max(mx, i - j + 1);
        }
        return mx;
    }
};
