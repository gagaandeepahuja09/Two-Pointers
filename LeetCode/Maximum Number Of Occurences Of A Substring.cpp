class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        vector<int> cnt(26, 0);
        map<string, int> mp;
        string str;
        int unique = 0, mx = 0;
        for(int i = 0; i < minSize; i++) {
            if(cnt[s[i] - 'a']++ == 0) {
                unique++;
            }
            str += s[i]; 
        }
        if(unique <= maxLetters) {
            mp[str]++;
            mx = max(mx, mp[str]);
        }
        for(int i = minSize; i < s.size(); i++) {
            if(cnt[s[i] - 'a']++ == 0) {
                unique++;
            }
            if(--cnt[s[i - minSize] - 'a'] == 0) {
                unique--;
            }
            str += s[i];
            str.erase(str.begin());
            if(unique <= maxLetters) {
                mp[str]++;
                mx = max(mx, mp[str]);
            }
        }
        return mx;
    }
};
